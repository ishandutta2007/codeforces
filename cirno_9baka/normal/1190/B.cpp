#include<stdio.h>
        #include<iostream>
        #include<algorithm>
    #include<queue>
    #include<string.h>
    using namespace std;
    int n,a[100005],i,l,flag;
long long ans;
    int main()
    {
    	scanf("%d",&n);
    	for(i=1;i<=n;i++)
        		scanf("%d",&a[i]);
        	sort(a+1,a+1+n);
        	if(a[1]==0&&a[2]==0)
        	    flag=2;
        	for(i=1;i<=n;i++)
        	{
        			ans+=a[i]-(i-1);
        		if(a[i]==a[i-1]&&i!=1)
    			{
    				flag++;
    				if(i>2&&(a[i-1]==a[i-2]+1||a[i]==0))
    					flag++;
    			}
        	}
        	if((ans&1)&&flag<2)
        		printf("sjfnb");
        	else
        		printf("cslnb");
        }