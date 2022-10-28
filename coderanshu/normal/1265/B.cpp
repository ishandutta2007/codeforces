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
	pair<long int,long int> p[200003];
	long int t,i,m,M,n;
	cin>>t;
	while(t--)
	{
		cin>>n;

		for(i=0;i<n;i++)
		{
			cin>>p[i].first;
			p[i].second=i+1;
		}
		sort(p,p+n);
		m=M=p[0].second;

		cout<<1;
		for(i=1;i<n;i++)
		{
			m=min(p[i].second,m);
			M=max(p[i].second,M);
			if(M-m==i)
				cout<<1;
			else cout<<0;
		}
		cout<<"\n";
	}
	return 0;
}