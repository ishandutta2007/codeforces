#include <bits/stdc++.h>
using namespace std;
struct num{
	long long x;
	int cnt3;
	void inp()
	{
		cin>>x;cnt3=0;
		long long _x=x;
		while(_x%3==0)
		{
			_x/=3;
			++cnt3;
		}
	}
};
bool operator<(const num&a,const num&b)
{
	if(a.cnt3!=b.cnt3) return a.cnt3>b.cnt3;
	return a.x<b.x;
}
int n;
num a[105];
int main()
{
	cin>>n;
	for(int i=0;i<n;++i) a[i].inp();
	sort(a,a+n);
	for(int i=0;i<n;++i)
	{
		cout<<a[i].x;
		if(i==n-1) cout<<endl;
		else cout<<' ';
	}
	return 0;
}