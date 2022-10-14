#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		if(a>0) a--,ans++;
		if(b>0) b--,ans++;
		if(c>0) c--,ans++;
		if(b>0 && c>0) b--,c--,ans++;
		if(a>0 && c>0) a--,c--,ans++;
		if(a>0 && b>0) a--,b--,ans++;
		if(a>0 && b>0 && c>0) a--,b--,c--,ans++;
		cout<<ans<<endl;
	}
	return 0;
}