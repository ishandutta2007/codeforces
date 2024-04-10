#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		int n,r=0,x;
		cin>>n;n<<=1;
		while (n--)
		{
			cin>>x;if (x&1) ++r; else --r;
		}
		if (r==0) cout<<"Yes\n"; else cout<<"No\n";
	}
}