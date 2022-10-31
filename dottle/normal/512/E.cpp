#include<bits/stdc++.h>
const int N=4050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}
int v[N],con[N];
vector<pair<int,int>>ans1,ans2;

int n,fl;

void push(int k){
	v[k]=-1;
	fore(k){
		if(v[_to]==0)
			v[_to]=k;
		else if(v[_to]!=-1){
			if(fl){
				if(!con[_to])ans1.push_back({k,v[_to]});
			}
			else{
				if(!con[_to])ans2.push_back({1,_to});
			}
			push(_to);
		}
	}
}

void solve(){
	memset(hd,0,sizeof(hd));S=0;
	memset(v,0,sizeof(v));
	memset(con,0,sizeof(con));
	v[1]=-1;
	for(int i=1;i<=n;i++)
		add(i,i%n+1),add(i%n+1,i);
	for(int i=1;i<=n-3;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
		if(x==1||y==1)
			con[x+y-1]=1;
	}
	fore(1)push(_to);
}

int main(){
	cin>>n;
	fl=1;solve();
//	cout<<endl;
	fl=0;solve();
	cout<<ans1.size()+ans2.size()<<endl;
	for(int i=0;i<ans1.size();i++)
		cout<<ans1[i].first<<' '<<ans1[i].second<<endl;
	for(int i=ans2.size()-1;~i;i--)
		cout<<ans2[i].first<<' '<<ans2[i].second<<endl;
}