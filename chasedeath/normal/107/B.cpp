#include<bits/stdc++.h>
using namespace std;
 
#define reg register
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
 
char IO;
int rd(){
    int s=0,f=0;
    while(!isdigit(IO=getchar())) if(IO=='-') f=1;
    do s=(s<<1)+(s<<3)+(IO^'0');
    while(isdigit(IO=getchar()));
    return f?-s:s;
}
 
 
const int N=1e3+10,P=1e9+7;

int n,m,p;
int a[N];
int s;
double dp[N][N],ans;


int main(){
	n=rd(),m=rd(),p=rd();
	rep(i,1,m) s+=(a[i]=rd());
	if(s<n) return puts("-1"),0;
	s--,a[p]--,n--;
	dp[0][0]=1;
	rep(i,0,n) {
		rep(j,0,min(i,a[p])) {
			dp[i+1][j+1]+=dp[i][j]*1.0*(a[p]-j)/(s-i);
			dp[i+1][j]+=dp[i][j]*1.0*(s-i-a[p]+j)/(s-i);
		}
	}
	//rep(i,1,n) rep(j,0,a[p]) cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	rep(i,1,a[p]) ans+=dp[n][i];
	printf("%.6lf\n",ans);
}