#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[600];
	int n,j,p;
	set<char> s;
	set<char>::iterator it;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if(strlen(a)==1)
		{
		    cout<<a<<"\n";;
		    continue;
		}
		for(j=0;j<strlen(a)-1;j++)
		{
			if(a[j]!=a[j+1])
			{
				s.insert(a[j]);
				
			}
			else{  p=j;j++;}

		}
		if(j==strlen(a)-1)
		{
		if(a[strlen(a)-1]!=a[strlen(a)-2])
				s.insert(a[strlen(a)-1]);
		else if(j-2==p)
				s.insert(a[strlen(a)-1]);
		}
		for(it=s.begin();it!=s.end();it++)
		cout<<*it;
		cout<<"\n";
		s.clear();
	}
	
	return 0;
}