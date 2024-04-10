#include<bits/stdc++.h>
using namespace std;
char ch[1000003];
int main()
{
	int n,l=0,tot=0,f=0,ans=0;
	scanf("%d",&n);
	scanf("%s",ch);
	for(int i=0; i<n; i++) if(ch[i]=='(') l++; else l--;
	if(l!=0) return 0&printf("-1"); else l=0;
	for(int i=0; i<n; i++) 
	{
		tot++;
		if(ch[i]=='(') l++;  
		else 
		{
			if(l==0) f=1;
			l--;
		}
		if(l==0) 
		{
			if(f) ans+=tot; 
			l=0,f=0,tot=0;
		}
	}
	cout<<ans;
	return 0;
}