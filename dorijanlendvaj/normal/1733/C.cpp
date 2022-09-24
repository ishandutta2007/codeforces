#include <bits/stdc++.h>
using namespace std;
const char en='\n';
int main() {
	int t, n, k, a;
cin>>t;
while (t--) {
cin>>n;
vector<int> h(n);
int mp=-1;
for (int i=0;i<n;++i)
{
cin>>h[i];
if ((h[i]+h[0])%2==0) mp=i;
}
cout<<n-1<<en;
for (int i=0;i<mp;++i)
{
if ((h[i]+h[0])%2==0) cout<<i+1<<' '<<mp+1<<en;
else cout<<"1 "<<i+1<<en;
}
for (int i=mp+1;i<n;++i) cout<<"1 "<<i+1<<en; 
} 
	return 0;
}