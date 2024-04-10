#include<bits/stdc++.h>
using namespace std;
 
pair<int,int> a[23456],b[23456];
int f[23456];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
		b[i]=a[i];
    }
    sort(b+1,b+n+1);
    f[b[1].second]=b[n].second;
    for(int i=2;i<=n;i++)
    {
    	f[b[i].second]=b[i-1].second;
	}
		
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[f[a[i].second]].first);
	}	
    return 0;
}