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
const int MAXN=1e5+10;
int T,n,a,b;
int p[MAXN];
void solve(){
	scanf("%d%d%d",&n,&a,&b);
	if(abs(a-b)>1){
		printf("-1\n");return;
	}
	if(a+b>n-2){
		printf("-1\n");return;
	}
	if(a==b){
		p[1]=1;
		for(int i=2;i<=n;i+=2){
			if(a){
				p[i]=i+1;p[i+1]=i;
				a--;
			}else{
				p[i]=i;p[i+1]=i+1;
			}
		} 
	}else if(a>b){
		p[1]=1;
		for(int i=2;i<=n;i+=2){
			if(b){
				p[i]=i+1;p[i+1]=i;
				b--;
			}else{
				rep(j,i,n){
					p[j]=n-(j-i);
				}
				break;
			}
		}
	}else{
		p[1]=2;p[2]=1;
		for(int i=3;i<=n;i+=2){
			if(a){
				p[i]=i+1;p[i+1]=i;
				a--;
			}else{
				p[i]=i;p[i+1]=i+1;
			}
		}
	}
	rep(i,1,n)printf("%d ",p[i]);printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}