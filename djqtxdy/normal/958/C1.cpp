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

const int maxn=100005;
int n,p,ans,sum;
int a[maxn];

int main(){
	scanf("%d%d",&n,&p);
	rep(i,n)scanf("%d",&a[i]),sum=(sum+a[i])%p;
	int cur=0;
	rep(i,n-1){
		cur=(cur+a[i])%p;
		int cur2=(sum-cur+p)%p;
		ans=max(ans,cur+cur2);
	}
	printf("%d",ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/