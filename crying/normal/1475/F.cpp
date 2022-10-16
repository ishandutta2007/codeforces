#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=1010;
int t,n,a[MAXN][MAXN],b[MAXN][MAXN],tmp[MAXN][MAXN];
char c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,1,n){
			rep(j,1,n)scanf(" %c",&c),a[i][j]=c-'0',tmp[i][j]=a[i][j]^1;
		}
		rep(i,1,n){
			rep(j,1,n)scanf(" %c",&c),b[i][j]=c-'0';
		}
		// 
		rep(j,1,n){
			if(a[1][j]!=b[1][j]){
				//j
				rep(i,1,n)a[i][j]^=1; 
			}
		}
		int flag=1;
		rep(i,2,n){
			int cnt=0;
			rep(j,1,n){
				if(a[i][j]!=b[i][j])cnt++;
			}
			if(cnt && cnt!=n){
				flag=0;break;
			}
		}
		if(flag)goto END; 
		rep(j,1,n){
			if(tmp[1][j]!=b[1][j]){
				//j
				rep(i,1,n)tmp[i][j]^=1; 
			}
		}
		flag=1;
		rep(i,2,n){
			int cnt=0;
			rep(j,1,n){
				if(tmp[i][j]!=b[i][j])cnt++;
			}
			if(cnt && cnt!=n){
				flag=0;break;
			}
		}
		if(flag)goto END; 
		printf("NO\n");
		continue;
		END:printf("YES\n");
	}
	
	return 0;
}