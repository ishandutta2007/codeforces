#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];
int a[15];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}     
    clock_t st=clock();
    while(1.0*(clock()-st)/CLOCKS_PER_SEC < 1.5);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	 printf("%d ",a[i]);
	}    
    return 0;
}