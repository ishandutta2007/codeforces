#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+100;
const int MAXK = 1e6+100;
typedef long long LL;
int m,n,k;
bool solved = false;
vector<pair<int,int> > a[MAX],b[MAX];
bool cmp(const pair<int,int> a,const pair<int,int>b){
	return a.first<b.first;
} 
LL ansl[MAXK],ansr[MAXK];
LL res;
int ll,rr;
void input(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int d,f,t,c;
		scanf("%d%d%d%d",&d,&f,&t,&c);
		if (f==0){
			b[t].push_back(make_pair(d,c));
		}else{
			a[f].push_back(make_pair(d,c));
		} 
	}
}
void init(){
	ll = -1;
	rr = 0x3f3f3f3f;
	for (int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end(),cmp);
		sort(b[i].begin(),b[i].end(),cmp);
		int dl = 0x3f3f3f3f;
		int dr = -1;
		for (vector<pair<int,int> >::iterator it = a[i].begin();it!=a[i].end();++it){
			dl = min(dl,it->first);
		}
		for (vector<pair<int,int> >::iterator it = b[i].begin();it!=b[i].end();++it){
			dr = max(dr,it->first);
		}
		if (dl==0x3f3f3f3f||dr==-1){
			solved = true;
			printf("-1\n");
			return;
		}
		ll = max (ll,dl);
		rr = min(rr,dr);
	}
	if (ll==-1||rr==0x3f3f3f3f){
		solved = true;
		printf("-1\n");
	}
}
void solve(){
	if (solved){
		return;
	}
	if (rr-ll-1<k){
		printf("-1\n");
		return ;
	}
	memset(ansl,0,sizeof ansl);
	memset(ansr,0,sizeof ansr);
	res = 0x3f3f3f3f3f3f3f3fLL;
	for (int i=1;i<=n;i++){
		int now = 1;
		int cost = 0x3f3f3f3f;
		for (int t = 0;t<a[i].size();++t){
			int temp = a[i][t].first;
//			cout<<"start "<<now<<" "<<temp<<" "<<cost<<endl;
			ansl[temp]-=cost;
			ansl[now]+=cost;
			now = temp;
			cost = min(cost,a[i][t].second);
		}
		ansl[(int)(1e6)+1]-=cost;
		ansl[now]+=cost;
		now =1e6;
		cost = 0x3f3f3f3f;
		for (int t = b[i].size()-1;t>=0;--t){
			int temp = b[i][t].first;
//			cout<<"end "<<temp<<" "<<now<<" "<<cost<<endl; 
			ansr[now+1]-=cost;
			ansr[temp+1]+=cost;
			now = temp;
			cost = min(cost,b[i][t].second);
		}
		ansr[1]+=cost;
		ansr[now+1]-=cost;
	}
	for (int i=1;i<=1e6;i++){
		ansl[i]+=ansl[i-1];
		ansr[i]+=ansr[i-1];
	} 
	for (int start = ll;start+k+1<=rr;start++){
		res = min(res,ansl[start]+ansr[start+k+1]);
//		cout<<"ans "<<start<<" "<<start+k+1<<" : "<<ansl[start]<<" "<<ansr[start+k+1]<<endl;
	}
	printf("%I64d\n",res);
}
int main(){
//	freopen("output.txt","w",stdout);
	input();
	init();
	solve();
	return 0;
}