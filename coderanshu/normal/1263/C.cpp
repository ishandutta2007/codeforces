#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long int t,n,i,count,j,k;
	cin>>t;
	while(t--)
	{
	set<long int> s;
	set<long int>::iterator it; 
	
		count=0;
		cin>>n;
		s.clear();
		k=sqrt(n);
		for(i=1;i<=k;i++)
		{
			//v.push_back(n/i);
			s.insert(i);
			s.insert(n/i);
		}
		s.insert(0);
		cout<<s.size()<<"\n";
		for(it=s.begin();it!=s.end();it++)
			cout<<*it<<" ";
		cout<<"\n";
	}
	return 0;
}