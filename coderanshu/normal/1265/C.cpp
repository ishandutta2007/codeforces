#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argarr[])
{
	ios_base::sync_with_stdio(0);
	long int arr[400005];
	
	long int be,en,g,t,s,b,n,i;
	map<long int,long int> m;
	vector<long int> temp;

	cin>>t;
	while(t--)
	{
		cin>>n;
		temp.clear();
		m.clear();
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(n<=9)
		{
			cout<<0<<" "<<0<<" "<<0<<"\n";continue;
		}
		for(i=0;i<=n/2-1;i++)
		{
			m[arr[i]]++;
		}
		
		if(arr[i]==arr[i-1])
		{
			m.erase(m.begin());
		}
		
		if(m.size()<3)
		{
			cout<<0<<" "<<0<<" "<<0<<"\n";
			continue;
		}
		else
		{
			for(auto j:m)
			{
				if(j.second!=0)
				temp.push_back(j.second);
			}
			g=temp[temp.size()-1];
			be=0;en=temp.size()-2;
			s=temp[en];b=temp[be];
			//cout<<be<<" "<<en;
			while(be+1!=en)
			{
				if(s>=b)
				{
					be++;
					b+=temp[be];
				}
				else if(b>s)
				{
					en--;
					s+=temp[en];
				}
			}
			if(g<s && g<b)
				cout<<g<<" "<<s<<" "<<b<<"\n";
			else cout<<0<<" "<<0<<" "<<0<<"\n";

		}
		
		
		
	}
	return 0;
}