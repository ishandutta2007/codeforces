#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN],x,y,next[MAXN],t[MAXN],ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),t[a[i]]=n+1;
	next[0]=n+1;
	per(i,n,1){next[i]=t[a[i]];t[a[i]]=i;}
	rep(i,1,n){
		if(a[i]==a[x] && a[i]==a[y])continue;
		if(a[i]==a[x]){x=i;}
		else if(a[i]==a[y]){y=i;}
		else{
			ans++;
			if(next[x]>next[y])x=i;
			else y=i;
		}
	}
	printf("%d",ans);
	return 0;
}