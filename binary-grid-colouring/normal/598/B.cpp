#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s;
	int t;
	cin>>t;
	while(t--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		l--;
		k = k % (r-l);
		rotate(s.begin() + l, s.begin() + r - k,s.begin() + r);
	}
	cout<<s<<endl;
	return 0;
 }