#include <bits/stdc++.h>
using namespace std;
const char en='\n';
int dp[5010][5010][2][2];
int main() {
	int t, n;
long long x, y;
string a, b;
cin>>t;
while (t--) {
cin>>n>>x>>y>>a>>b;
vector<int> h(n);
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
//
} 
	return 0;
}