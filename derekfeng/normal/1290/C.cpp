#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
const int N=300300;
int n,m;
char s[N];
vector<int>a[N];
int sz[N];
pii par[N];
int b[N][2];
int curAns=0;
pii getPar(int v){
	int res=0;
	while(par[v].first!=v){
		res^=par[v].second;
		v=par[v].first;
	}
	return mp(v,res);
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);
			x--;
			a[x].push_back(i);
		}
	}
	for (int i=0;i<m;i++){
		sz[i]=1;
		par[i]=mp(i,0);
		b[i][0]=0;
		b[i][1]=1;
	}
	for (int i=0;i<n;i++){
		int k=(int)a[i].size();
		if (k==0); 
		else if (k==1){
			int v=a[i][0];
			pii p=getPar(v);
			v=p.first;
			int t=p.second;
			if (s[i]=='0') t^=1;
			t^=1;
			curAns-=min(b[v][0],b[v][1]);
			b[v][t]=N;
			curAns+=min(b[v][0],b[v][1]);
		}else{
			int v=a[i][0],u=a[i][1];
			pii pv=getPar(v),pu=getPar(u);
			v=pv.first;
			u=pu.first;
			int t=pv.second^pu.second;
			if (s[i]=='0')t^=1;
			if (v!=u){
				if (sz[v]<sz[u]) swap(v,u);
				par[u]=mp(v,t);
				sz[v]+=sz[u];
				curAns-=min(b[v][0],b[v][1]);
				curAns-=min(b[u][0],b[u][1]);
				for (int j=0;j<2;j++) {
					b[v][j]+=b[u][j^t];
					b[v][j]=min(b[v][j],N);
				}
				curAns+=min(b[v][0],b[v][1]);
			}
		}
		printf("%d\n", curAns);
	}
	return 0;
}