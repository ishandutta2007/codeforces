/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=1005;
int n,ans;
int deg[maxn];

int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		deg[u]++;
		deg[v]++;
	}
	rep(i,n)if(deg[i]==1)ans++;
	printf("%d",ans); 
	return 0;
}

/*
Input:
-----------------
Output:
*/