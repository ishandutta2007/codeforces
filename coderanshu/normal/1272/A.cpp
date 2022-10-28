#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	long int a[3];
	cin>>t;
	while(t--)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[2]-a[0]<2)
			cout<<"0\n";
		else
		{
			cout<<2*(a[2]-a[0]-2)<<"\n";
		}

	}
	return 0;
}