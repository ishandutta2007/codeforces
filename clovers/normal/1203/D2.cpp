#include<bits/stdc++.h>
using namespace std;
const int N=200001;

char a[N],s[N],tmpa[N],tmps[N];
int l[N],r[N],t[N],n,m;

bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int lpos=i;
		int rpos=i+x-1;
		if(l[lpos-1]+r[rpos+1]>=m) return 1;
	}
	return 0;
}

int main()
{
	scanf("%s",a+1); 
	scanf("%s",s+1); 
	n=strlen(a+1);
	m=strlen(s+1);
	for(int i=1;i<=n;i++) tmpa[i]=a[n+1-i];
	for(int i=1;i<=m;i++) tmps[i]=s[m+1-i];
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(s[j+1]==a[i+1]) j++;
		t[i+1]=j;
	}
	for(int i=1;i<=n;i++) l[i]=max(l[i-1],t[i]);
	j=0;
	for(int i=0;i<n;i++) 
	{
		if(tmps[j+1]==tmpa[i+1]) j++;
		t[n-i]=j;
	}
	for(int i=n;i>=1;i--) r[i]=max(r[i+1],t[i]);
	int L=0,R=n-m,mid,best=-1;
	while(L<=R)
	{
		mid=(R+L)>>1;
		if(check(mid)) L=mid+1,best=mid;
		else R=mid-1;
	}
	cout<<best<<endl;
	return 0;
}