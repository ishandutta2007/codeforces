#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;



int n,m;
double dp[N];

int main(){
	n=rd(),m=rd();
	dp[1]=1;
	double ans=0;
	int l=1,r=2;
	rep(i,1,n) {
		while(dp[l]<1e-14) l++;
		while(dp[r]>1e-14) r++;
		drep(j,r,l) {
			double t=1.0/((j+1)*m);
			ans+=dp[j]*(j*(j+1)/2+j)/(j+1);
			dp[j+1]+=dp[j]*t;
			dp[j]*=(1-t);
		}
	}
	//rep(i,1,n) cout<<dp[i]<<' ';puts("");
	printf("%.9lf\n",ans);
}