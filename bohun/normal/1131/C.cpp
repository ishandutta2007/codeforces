#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n;
int t[105];	
vector < int > v;
bool ok[105];
bool f(int x)
{
	if(x>t[n]-t[1])
		return 1;
	ok[1]=ok[n]=1;
	for(int i=2;n>i;i++)
		ok[i]=0;
	int gdzie=t[1];
	v.push_back(1);
	for(int i=1;n>=i;i++)
	{
		for(int j=n-1;j>=1;j--)
		{
			if(abs(gdzie-t[n])<=x)
				break;
			if(abs(gdzie-t[j])<=x and ok[j]==0)
			{
				v.push_back(j);
				gdzie=t[j];
				ok[j]=1;
				break;
			}
		}
		if(abs(gdzie-t[n])<=x)
				break;
	}
	v.push_back(n);
	if(abs(gdzie-t[n])>x)
		return 0;
	gdzie=t[1];
	vector < int > X;
	for(int i=1;n>=i;i++)
	{
		if(abs(gdzie-t[i])<=x and ok[i]==0)
		{
			X.push_back(i);
			gdzie=t[i];
			ok[i]=1;
		}
	}
	if(abs(gdzie-t[n])>x)
		return 0;
	reverse(X.begin(),X.end());
	for(auto it: X)
		v.push_back(it);
	return 1;
}
int main()
{	
	cin>>n;
	for(int i=1;n>=i;i++)
		cin>>t[i];
	sort(t+1,t+n+1);
	int l=0;
	int p=1e9+5;
	while(p>l)
	{
		int mid=(l+p)/2;
		if(f(mid)==1)
			p=mid;
		else
			l=mid+1;
		v.clear();
	}
	f(l);
	for(auto it: v)
		cout<<t[it]<<" ";
		
    return 0;	
}