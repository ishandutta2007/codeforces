#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, k, a;
cin>>t;
while (t--) {
cin>>n>>k>>a;
if (k>a) swap(k, a);
if (k!=0 || a==0 || (n-1)%a)
{
cout<<-1<<endl;
continue;
}
for (int i=0;i<n-1;++i) cout<<2+i/a*a<<' ';
cout<<endl;
} 
	return 0;
}