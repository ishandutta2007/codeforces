#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MAXN=1e3+10,moder=1e9+7;
int T,n,k,a[MAXN],t[MAXN];
int C[MAXN][MAXN];
int main(){
	scanf("%d",&T);
	C[0][0]=1;
	rep(i,1,1000){
		C[i][0]=1;
		rep(j,1,i){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%moder;
		}
	}
	while(T--){
		memset(t,0,sizeof t);
		scanf("%d%d",&n,&k);
		rep(i,1,n){
			scanf("%d",&a[i]);t[a[i]]++;
		}
		sort(a+1,a+1+n,greater<int>());
		int num=t[a[k]],cnt=0;
		rep(i,1,k)if(a[i]==a[k])cnt++;
		//C(num,cnt)
		printf("%d\n",C[num][cnt]);
	} 
	
	return 0;
}