#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
int T,a,b,c,d,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
		rep(x1,0,1){
			rep(x2,0,1){
				rep(x3,0,1){
					rep(x4,0,1){
						// 
						if(a-x1-x2<0 || a>n-2+x1+x2)continue;
						if(b-x2-x3<0 || b>n-2+x2+x3)continue;
						if(c-x3-x4<0 || c>n-2+x3+x4)continue;
						if(d-x1-x4<0 || d>n-2+x1+x4)continue;
						goto END;
					}
				}
			}
		}
		printf("NO\n");continue;
		END:printf("YES\n");
	}
	return 0;
}