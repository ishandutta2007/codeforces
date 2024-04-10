#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
int pri[3000000],tot;
bitset<N+3>flg;
void init(){
	flg[1]=1;
	for(int i=2;i<=N;i++){
		if(!flg[i])pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j]<=N;j++){
			flg[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int t,n,m;
int a[200004],lst[200004],nxt[200004];
vector<int>p[200004];
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)p[i].clear();
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		if(x==1)a[i]=0;
		else if(!flg[x])a[i]=1;
		else a[i]=2;
		p[i%m].push_back(i);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p[i].size();j++){
			lst[p[i][j]]=-1;
			if(j>0){
				lst[p[i][j]]=lst[p[i][j-1]];
				if(a[p[i][j-1]]!=0)lst[p[i][j]]=p[i][j-1];
			}
		}
		reverse(p[i].begin(),p[i].end());
		for(int j=0;j<p[i].size();j++){
			nxt[p[i][j]]=-1;
			if(j>0){
				nxt[p[i][j]]=nxt[p[i][j-1]];
				if(a[p[i][j-1]]!=0)nxt[p[i][j]]=p[i][j-1];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)if(a[i]==1){
		int L=i-1,R=n-i;
		L=L/m+1,R=R/m+1;
		if(lst[i]!=-1)L=(i-lst[i])/m;
		if(nxt[i]!=-1)R=(nxt[i]-i)/m;
		ans+=(ll)L*R-1;
	}
	printf("%lld\n",ans);
}
int main(){
	init();
	scanf("%d",&t);
	while(t--)sol();
}