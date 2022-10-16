#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=5e4+10;
int T,n,a[MAXN],x;
int f[MAXN];
void solve(){
	memset(f,0,sizeof f);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&x);
	rep(i,1,n)a[i]-=x;
	f[1]=f[2]=1;
	if(a[1]+a[2]>=0)f[2]=2;
	rep(i,3,n){
		if(a[i]>=0){
			if(a[i]+a[i-1]>=0){
				f[i]=max(f[i],f[i-1]+1);
			}
		}else{
			if(a[i]+a[i-1]>=0){
				int val=a[i]+a[i-1];
				if(val+a[i-2]>=0){
					f[i]=max(f[i],f[i-2]+2);
				}else{
					f[i]=max(f[i],f[i-3]+2);
				}
			}
		}
		f[i]=max(f[i],f[i-2]+1);
	} 
	printf("%d\n",f[n]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}