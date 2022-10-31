#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int a[200000],b[200000],c[200000];
int num,sum,n,m,ans,bmax,cmax;
map<int,int>data;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    
    sort(a+1,a+n+1);
    data.clear();
    sum=1;
    for(int i=2;i<=n;i++)
    {
    	if (a[i]!=a[i-1])
    	{
    		data.insert(pair<int,int>(a[i-1],sum));
    		sum=0;
    	}
    	sum++;
    }
    data.insert(pair<int,int>(a[n],sum));
    ans=1;
    bmax=data[b[1]];
    cmax=data[c[1]];
    for(int i=2;i<=m;i++)
    	if ((data[b[i]]>bmax)||((data[b[i]]==bmax)&&(data[c[i]]>cmax)))
    	{
    		ans=i;
    		bmax=data[b[i]];
    		cmax=data[c[i]];
    	}
    cout<<ans<<endl;
    return 0;
}