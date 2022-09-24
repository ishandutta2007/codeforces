#include <bits/stdc++.h>
using namespace std;
const char en='\n';
int dp[5010][5010][2];
int main() {
	int t, n;
long long x, y;
string a, b;
cin>>t;
while (t--) {
cin>>n>>x>>y>>a>>b;
vector<int> h(n+1);
int xx=0;
for (int i=0;i<n;++i) h[i]=a[i]^b[i], xx^=h[i];
if (xx) 
{
cout<<-1<<en;
continue;
} 
if (x>=y)
{
int cn=0, zaj=0;
for (int i=0;i<n;++i) cn+=h[i];
for (int i=0;i<n-1;++i) zaj+=h[i]*h[i+1];
if (cn==2 && zaj==1) cout<<min(x, 2*y)<<en;
else cout<<y*cn/2<<en;
continue;
}
for (int i=0;i<=n;++i) for (int op=0;op<=i;++op) for (int s=0;s<2;++s) dp[i][op][s]=398577; 
dp[0][0][h[0]]=0;
for (int i=1;i<=n;++i) for (int op=0;op<i;++op) for (int s=0;s<2;++s) for (int u=0;u<2;++u) dp[i][op+u][h[i]^u]=min(dp[i][op+u][h[i]^u], dp[i-1][op][s]+(s^u));
long long mi=x*n+y*n;
for (int op=0;op<n;++op) if (dp[n][op][0]<300000) mi=min(mi, x*op+y*dp[n][op][0]/2);
cout<<mi<<en;
} 
	return 0;
}