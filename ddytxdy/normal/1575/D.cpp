#include<bits/stdc++.h>
using namespace std;
int ans,n,p=-1,a[15];
char s[15];
void dg(int x)
{
	if (!x)
	{
		if (a[1]==0) return;
		vector<int>t;
		for (int i=1;i<=n;i++) 
		{
			if (s[i]=='X') t.emplace_back(a[i]);
			else if (s[i]>='0' && s[i]<='9' && s[i]-'0'!=a[i]) return;
		}
		sort(t.begin(),t.end());
		if (!t.empty() && t[0]!=t[t.size()-1]) return;
		ans++;
		return;
	}
	if (x==n)
	{
		a[n]=0;
		a[n-1]=0;
		dg(x-2);
		a[n]=5;
		a[n-1]=2;
		dg(x-2);
		a[n]=5;
		a[n-1]=7;
		dg(x-2);
		a[n]=0;
		a[n-1]=5;
		dg(x-2);
		return;
	}
	if (s[x]>='0' && s[x]<='9') dg(x-1);
	if (s[x]=='_' || s[x]=='X')
	{
		for (int i=0;i<10;i++) a[x]=i,dg(x-1);
	}
}
int main(){
	cin>>s+1;
	n=strlen(s+1);
	if (n==1)
	{
		if (s[1]=='0' || s[1]=='X' || s[1]=='_') printf("1"); else printf("0");
		return 0;
	}
	for (int i=1;i<=n;i++) if (s[i]>='0' && s[i]<='9') a[i]=s[i]-'0';
	dg(n);
	printf("%d",ans);
	return 0;
}