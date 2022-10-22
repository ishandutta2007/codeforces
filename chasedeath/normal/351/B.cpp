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


const int N=3e3+10,P=1e9+7;

int n,m,p;
int a[N];
double dp[N*N];




int main(){
	n=rd();
	rep(i,1,n) {
		a[i]=rd();
		rep(j,1,i) if(a[j]>a[i]) m++;
	}
	dp[0]=0;
	if(m&1) {
		dp[1]=1;
		rep(i,2,m) {
			dp[i]=dp[i-2]+4;
		}
		printf("%.6lf\n",dp[m]);
	} else {
		rep(i,2,m) {
			dp[i]=dp[i-2]+4;
		}
		printf("%.6lf\n",dp[m]);
	}
}