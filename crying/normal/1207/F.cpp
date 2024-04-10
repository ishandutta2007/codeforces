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
const int MAXN=5e5+10;
int n=500000,q,t,x,y,lim=sqrt(500000)+1;
ll a[MAXN];
vector<ll>sum[MAXN];
int main(){
	scanf("%d",&q);
	rep(i,1,lim)sum[i].resize(i+10);
	rep(i,1,q){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			rep(j,1,lim){
				sum[j][x%j]+=y;
			}
			a[x]+=y;
		}else{
			if(x<=lim)printf("%lld\n",sum[x][y]);
			else{
				ll s=0;
				rep(j,0,n){
					if(x*j+y>n)break;
					s+=a[x*j+y];
				}
				printf("%lld\n",s);
			}
		}
	}
	
	return 0;
}