// Problem: B. New Year and Ascent Sequence
// Contest: Codeforces - Hello 2020
// URL: https://codeforces.com/contest/1284/problem/B
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int l[1000003],r[1000003];
int a[1000003];
int cnt;
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++)
	{
		int x,mn=1e18,mx=-1e18,t=0;
		x=read();
		for(int j=1;j<=x;j++) 
		{
			cin>>a[j];
			if(a[j]>mx) mx=a[j];
			if(a[j]<mn) mn=a[j];
			if(j>=2 && a[j]>a[j-1]) t=1;
		}
		if(t==0) ++cnt,l[cnt]=mn,r[cnt]=mx;
	}
	sort(l+1,l+1+cnt);
	sort(r+1,r+1+cnt);
	int ans=0;
	int now=1;
	for(int i=1;i<=cnt;i++)
	{
		int x=l[i];
		while(r[now]<=x && now<=cnt) ++now;
		ans=ans+cnt-now+1+(n-cnt);
	}
	cout<<ans+(n-cnt)*n<<endl;
    return 0;
}