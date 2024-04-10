#include <bits/stdc++.h>
using namespace std;
string s,t,t1,p;
string cut(string h,int c)
{
	return h.substr(c+1);
}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
	cin>>s>>t>>p;
	t1=t;
	bool o=1;
	for(int i=0;i<s.size();i++)
	{
		if(t1.find(s[i])>10000)
		o=0;
		else
		{
		t1=cut(t1,t1.find(s[i]));
		}
	}
	int a[27]={0};
	if(o)
	{
		for(int i=0;i<s.size();i++)
		a[s[i]-'a']++;
		for(int i=0;i<t.size();i++)
		a[t[i]-'a']--;
		for(int i=0;i<p.size();i++)
		a[p[i]-'a']++;
		for(int i=0;i<26;i++)
		{
			if(a[i]<0)
			o=0;
		}
	}
	if(o)
	cout<<"YES\n";
	else
	cout<<"NO\n";
	}
	return 0;
}