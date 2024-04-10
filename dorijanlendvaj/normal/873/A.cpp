#include <bits/stdc++.h>

using namespace std;

int n,k,x,rj;
int h[100001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k>>x;
	for (int i=0;i<n;++i) cin>>h[i];
	sort(h,h+n);
	reverse(h,h+n);
	for (int i=0;i<k;++i) rj+=x;
	for (int i=k;i<n;++i) rj+=h[i];
	cout<<rj<<endl;
}