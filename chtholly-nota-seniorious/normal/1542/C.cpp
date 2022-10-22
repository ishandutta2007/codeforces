#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int p=1e9+7;
int a[100];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		ll n,r=0;cin>>n;
		for (int i=1;n;i++)
		{
			int x=i;
			for (int j=1;j<i;j++) if (x%a[j]==0) x/=a[j];
			a[i]=x;
			r=(r+i*((n-n/x)%p)%p)%p,n/=x;
		}
		cout<<r%p<<'\n';
	}
}