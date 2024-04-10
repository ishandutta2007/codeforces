#include <bits/stdc++.h>

using namespace std;

int n;
int h[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n*2;++i) cin>>h[i];
	sort(h,h+n*2);
	if (h[n-1]==h[n]) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}