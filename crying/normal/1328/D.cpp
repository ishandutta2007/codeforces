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
#define pr pair
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int q,n,a[MAXN],k,f[MAXN][3],color[MAXN];
vector<int>arr;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);k=0;
		rep(i,1,n)scanf("%d",&a[i]),color[i]=0,f[i][1]=f[i][2]=0;
		a[n+1]=color[n+1]=0;
		rep(i,2,n)if(a[i]!=a[i-1])goto FAIL;
		printf("1\n");
		rep(i,1,n)printf("1 ");printf("\n");
		continue;
		FAIL:;
		//11
		f[1][1]=1;
		rep(i,2,n){
			if(a[i]!=a[i-1]){
				f[i][1]=f[i-1][2];
				f[i][2]=f[i-1][1];
			}else{
				f[i][1]=f[i][2]=1;
			}
		}
		if(a[n]==a[1] || f[n][2]){
			printf("2\n");
			if(a[n]==a[1] && f[n][1])color[n]=1;
			else color[n]=2;	
			per(i,n,2){
				if(a[i]!=a[i-1]){
					if(color[i]==1)color[i-1]=2;
					else color[i-1]=1;
					if(!f[i-1][color[i-1]])swap(color[i],color[i-1]);
				}else{
					color[i-1]=1; // 
				}
			}
			color[1]=1;
		}else{
			printf("3\n");
			color[1]=1;
			rep(i,2,n-1){
				if(a[i]==a[i-1])color[i]=color[i-1];
				else{
					if(color[i-1]==1)color[i]=2;
					else color[i]=1;
				}
			}
			color[n]=3;
		}
		rep(i,1,n)printf("%d ",color[i]);
		printf("\n");
	}
	return 0;
}