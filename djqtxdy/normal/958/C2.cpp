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

const int maxn=20005;
const int maxk=55;
const int maxp=105;
int n,k,p;
int a[maxn],dp[maxn][maxk],mx[maxk][maxp];

int main(){
	scanf("%d%d%d",&n,&k,&p);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,k)rep(j,p)mx[i][j]=-INF;
	int sum=0;
	rep(i,n){
		sum=(sum+a[i])%p;
		rep(j,k){
			if(!j)dp[i][j]=sum;
			else{
				rep(q,p)
				if(mx[j-1][(sum-q+p)%p]!=-INF)
				dp[i][j]=max(dp[i][j],mx[j-1][(sum-q+p)%p]+q);
			}
			mx[j][sum]=max(mx[j][sum],dp[i][j]);
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	printf("%d",dp[n-1][k-1]);
	return 0;
}

/*
Input:
-----------------
Output:
*/