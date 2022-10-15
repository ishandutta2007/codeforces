#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int n,v[N];

void Print()
{
	for(int i=1;i<=n;i++)
		cout<<char(v[i]+'a');
	exit(0);
}

int main()
{
	int need;
	cin>>n>>need;
	string a,b;
	cin>>a>>b;
	a="x"+a;
	b="x"+b;
	for(int i=1;i<=n;i++)
		v[i]=-1;
	need=n-need;
	for(int i=1;i<=n;i++)
	{
	   	if(need==0)
			break;	
		if(a[i]==b[i])
		{
			v[i]=a[i]-'a';	
			need--;		
		}
	}		
	if(need==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(v[i]!=-1)
				continue;		
			v[i]=0;
			while(v[i]==a[i]-'a' || v[i]==b[i]-'a')
				v[i]++; 
		}		
		Print();
	}
	int have=0;
	for(int i=1;i<=n;i++)
		if(v[i]==-1)
			have++;
	if(2*need>have)
	{
		cout<<"-1\n";
		return 0;
	}
	int F=need,S=need;
	for(int i=1;i<=n;i++)
	{
		if(v[i]!=-1)
			continue;
		if(F)
		{
			v[i]=a[i]-'a';
			F--;
			continue;	
		}	
		if(S==0)
			break;			
		v[i]=b[i]-'a';
		S--;		
	}
//	cout<<need<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(v[i]!=-1)
			continue;		
		v[i]=0;
		while(v[i]==a[i]-'a' || v[i]==b[i]-'a')
			v[i]++; 
	}
	Print();
	return 0;
}