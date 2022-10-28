#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
 
#define FORG(i,a,n) for(lld i=a;i<n;i++) //for - general
#define FORZ(i,n) for(lld i=0;i<n;i++) //for - zero
#define FORGI(i,a,n,inc) for(lld i=a;i<n;i+=inc) //for - general incremental
#define FORZI(i,n,inc) for(lld i=0;i<n;i+=inc) //for - zero incremental
#define DEBUG(x) cerr<<(#x)<<" is "<<(x)<<endl //to debug values of variables
#define ZINDA cerr<<"\nIdhar-ich hai apun!!\n"; //to debug if code reached that point
#define SPEEDUP ios_base::sync_with_stdio(0); ifs.tie(NULL); cout.tie(NULL);
 
#define SORTall(m) sort(m.begin(),m.end());
 
#define st first
#define nd second
#define pb push_back
 
typedef long long int lld;
typedef unsigned long long int ulld;
 
lld power(lld b, lld e)
{
	if(e==0)
		return 1;
	if(e%2==1)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
 
//--------------------------------------------------------------------------------
int main()
{
	//SPEEDUP;

	ifstream ifs("t.txt");
	string s;
	cin>>s;

	lld n=s.length(),c=0;
	vector<lld> a,b,rest;
	FORZ(i,n)
	{
		if(s[i]=='(')
			a.pb(i);
		
		if(s[i]==')')
			b.pb(i);
	}

	for(lld i=0,j=b.size()-1 ; i<a.size() && j>=0 && i>=0 && j<s.size();)
	{
		if(a[i]<b[j])
		{
			rest.pb(a[i]);
			rest.pb(b[j]);
		
			i++;
			j--;
			c++;
		}
		else
		{
			j--;
		}
	}

	if(c==0)
	{ 
		cout<<c<<endl;return 0;
	}
	else
		cout<<"1\n"<<c*2<<endl;
	
	SORTall(rest);
	
	FORZ(i,rest.size())
		cout<<rest[i]+1<<" ";
	return 0;
}