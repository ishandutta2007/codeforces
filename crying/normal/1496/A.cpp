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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110; 
int T,n,k;
char str[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		scanf("%s",str+1);
		rep(i,1,n){
			rep(j,i,n){
				int L=i-1,R=n-j;
				if(L<k||R<k)continue;
				if(L!=R)continue;
				int cnt=1,flag=1;
				while(cnt<i){
					if(str[cnt]!=str[n-cnt+1]){
						flag=0;break;
					}
					cnt++;
				}
				if(flag)goto END;
			}
		}
		printf("NO\n");continue;
		END:printf("YES\n");
	}
	return 0;
}