#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

string s;
int main()
{
	cin>>s;
	bool flag = 0;

	if(s[0]=='@' || s[s.size()-1]=='@')
	{
		flag = 1;
//		cout<<"No solution"<<endl;
//		exit(0); 
	}
	int k = 0;
	for(int i=1;s[i];i++)
	{
		if(s[i]=='@'){
			k = 1;
		}
		if(s[i]=='@' && (s[i-1]=='@'||(i>1 &&s[i-2]=='@')))
		{
			flag = 1;
			cout<<"No solution"<<endl;
			exit(0);
		}
	}
	if(flag==1 || k==0)
	{
		cout<<"No solution"<<endl;
		exit(0);
	}
	for(int i=0;s[i];i++)
	{
		cout<<s[i];
		if(s[i]=='@') flag = 1;
		if(flag==1 && s[i+2]=='@')
		{
			cout<<",";
		}
	}
	cout<<endl;
}