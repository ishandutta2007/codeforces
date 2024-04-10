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

const int maxn=2005;
const int maxm=205;
const ll H=19260817;
int n,m;
ll h1[maxn][maxm],h2[maxm][maxn],pw[maxn];
char c[maxn];

ll get_hash(ll *h,int l,int r){
	return h[r]-(!l?0:h[l-1]*pw[r-l+1]);
}

bool check(int row,int col){
	rep(i,m){
		if(h1[row+i][m-1]!=get_hash(h2[i],col,col+m-1))return false;
	}
	return true;
}

int main(){
	pw[0]=1;
	REP(i,2000)pw[i]=pw[i-1]*H;
	scanf("%d%d",&n,&m);
	rep(i,n){
		scanf("%s",c);
		h1[i][0]=c[0];
		REP(j,m-1)h1[i][j]=h1[i][j-1]*H+c[j];
	}
	rep(i,m){
		scanf("%s",c);
		h2[i][0]=c[0];
		REP(j,n-1)h2[i][j]=h2[i][j-1]*H+c[j];
	} 
	rep(i,n)rep(j,n)if(check(i,j)){
		printf("%d %d",i+1,j+1);
		return 0;
	}
	return 0;
}

/*
Input:
-----------------
Output:
*/