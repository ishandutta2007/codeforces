#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,i,n,j,p,one,zero,sum;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		one=zero=0;
		vector<int> v(n);
		v.clear();
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<s.length();j++)
			{
				if(s[j]=='1')one++;
				else zero++;
			}
			v[i]=s.length()/2;
		}
		sort(v.begin(),v.end());
		p=zero/2+one/2;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=v[i];
			if(sum>p)
				break;
		}
		
		cout<<i<<"\n";

	}
	return 0;
}