#include<bits/stdc++.h>
using namespace std;
int n,a,b,tot,ans=999;
vector<int>v1,v2;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		tot+=a;
		if(a==1)v1.push_back(b);
		else v2.push_back(b);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int h=tot,res=tot,i;
	for(i=0;i<v1.size()&&h-1-v1[i]>=0;i++)
		h=h-1-v1[i],
		res--;
	i--;
	for(i;i>=-1;i--)
	{
		int tmp=h,res2=res;
		for(int j=0;j<v2.size()&&tmp-v2[j]-2>=0;j++)
			tmp=tmp-2-v2[j],
			res2-=2;
		ans=min(ans,res2);
		if(i>-1)
			h=h+1+v1[i],
			res++;
	}
	cout<<ans;
}