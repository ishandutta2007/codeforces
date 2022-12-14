#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
int main()
{
	string a;getline(cin,a);
	re len=a.length(),st=-1,ed=-1,l=-1,r=-1,ans=0;
	for(re i=0;i<len;i++) if(a[i]=='[') {st=i;break;} 
	for(re i=len-1;i>=0;i--) if(a[i]==']') {ed=i;break;}
	if(ed<=st||st==-1||ed==-1) 
	{
		puts("-1");return 0;
	}
	for(re i=st;i<=ed;i++) if(a[i]==':') {l=i;break;} 
	for(re i=ed;i>=st;i--) if(a[i]==':') {r=i;break;}
	if(l==r)
	{
		puts("-1");return 0;
	}
	for(re i=l;i<=r;i++)
	ans+=(a[i]=='|');
	cout<<ans+4;
	return 0;
}