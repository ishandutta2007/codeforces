#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb() push_back()
#define pp() pop_back()
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
	cin >>n;
	lli ar[n];
	for(lli i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	lli lg=1,l=1,mini=0,mn=ar[0];
	for(lli i=1;i<n;i++)
	{
		if(ar[i]>2*ar[i-1])
		{
			l=0;
		}
		l++;
		if(l>lg)
		lg=l;
	}
	cout<<lg;
	return 0;
}