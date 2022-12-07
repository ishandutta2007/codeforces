#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int q[6], n, err=0;
	for(int a=0; a<6; a++) cin>>q[a];
	string si[]={"S", "M", "L", "XL", "XXL", "XXXL"};
	cin>>n;
	int an[n];
	stack <int> s1[6], s2[6];
	for(int a=0; a<n; a++)
	{
		int two=0;
		string s;
		cin>>s;
		if(s.find(',')!=string::npos)
		{
			s=s.substr(0, s.find(','));
			two=1;
		}
		for(int b=0; b<6; b++)
		{
			if(s==si[b])
			{
				if(two) s2[b].push(a);
				else s1[b].push(a);
			}
		}
	}
	for(int a=0; a<6; a++)
	{
		if(a!=5)
		{
			if(q[a]>=s1[a].size())
			{
				while(s1[a].size()!=0)
				{
					an[s1[a].top()]=a;
					s1[a].pop();
					q[a]--;
				}
				while((q[a]>0)and(s2[a].size()>0))
				{
					an[s2[a].top()]=a;
					s2[a].pop();
					q[a]--;
				}
				while(s2[a].size()!=0)
				{
					s1[a+1].push(s2[a].top());
					s2[a].pop();
				}
			}
			else
			{
				err=1;
				break;
			}
		}
		else
		{
			if(s1[a].size()+s2[a].size()<=q[a])
			{
				while(s1[a].size()!=0)
				{
					an[s1[a].top()]=a;
					s1[a].pop();
				}
				while(s2[a].size()!=0)
				{
					an[s2[a].top()]=a;
					s2[a].pop();
				}
			}
			else
			{
				err=1;
				break;
			}
		}
	}
	if(err) cout<<"NO";
	else
	{
		cout<<"YES"<<"\n";
		for(int a=0; a<n; a++) cout<<si[an[a]]<<"\n";
	}
}