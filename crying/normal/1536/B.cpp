#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=1e4+10;
int T,n;
char s[MAXN],ans[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		ans[1]=ans[2]=ans[3]=ans[4]=0;
		int flag=0;
		rep(i,0,25){
			if(flag)break;
			ans[1]='a'+i;
			int valid=1;
			rep(j,1,n){
				if(s[j]==ans[1]){
					valid=0;break;
				}
			}
			if(valid){
				flag=1;
				printf("%s\n",ans+1);break;
			}
		}
		if(flag)continue;
		rep(i,0,25){
			if(flag)break;
			ans[1]='a'+i;
			rep(j,0,25){
				ans[2]='a'+j;
				int tmp=0;
				int valid=1;
				rep(k,1,n-1){
					if(s[k]==ans[1] && s[k+1]==ans[2]){
						valid=0;break;
					}
				}
				if(valid){
					flag=1;
					printf("%s\n",ans+1);break;
				}
			}
		}
		if(flag)continue;
		rep(i,0,25){
			if(flag)break;
			ans[1]='a'+i;
			rep(j,0,25){
				if(flag)break;
				ans[2]='a'+j;
				rep(k,0,25){
					ans[3]='a'+k;
					int valid=1;
					rep(x,1,n-2){
						if(s[x]==ans[1] && s[x+1]==ans[2] && s[x+2]==ans[3]){
							valid=0;break;
						}
					}
					if(valid){
						flag=1;
						printf("%s\n",ans+1);break;
					}
				}
			}
		}
	}

	return 0;
}