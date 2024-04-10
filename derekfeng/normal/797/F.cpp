#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int B=5e3;
const ll inf=1e18;
int n,m,S,T;
pair<int,ll>dq[10004];
vector<pii>all;
ll f[10004];
int main(){
	scanf("%d%d",&n,&m);int sm=0;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		all.push_back({x,-1});
	}
	for(int i=1;i<=m;i++){
		int x,c;scanf("%d%d",&x,&c);
		all.push_back({x,c});sm+=c;
	}
	if(sm<n){puts("-1");return 0;}
	sort(all.begin(),all.end());
	fill(f,f+B+B+1,inf);f[B]=0;
	for(int i=0;i<all.size();i++){
		ll p=all[i].fi;int c=all[i].se;
		if(c<0){
			for(int j=B+B;j;j--){
				if(j>B)f[j]=f[j-1]-p;
				else f[j]=f[j-1]+p;
			}
			f[0]=inf;
		}else{
			S=1,T=0;ll lev=0;
			for(int j=B+B;~j;j--){
				lev+=j<B?-p:p;
				while(S<=T&&dq[S].fi>j+c)S++;
				while(S<=T&&dq[T].se+lev>=f[j])T--;
				dq[++T]={j,f[j]-lev};
				f[j]=dq[S].se+lev;
			}
		}
	}
	printf("%lld",f[B]);
}