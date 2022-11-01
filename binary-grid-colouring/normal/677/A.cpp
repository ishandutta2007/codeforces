#include<iostream>       
#include<cstdlib>      
#include<cstdio> 
#include<cstring>      
#include<cmath>           
#include<string>      
#include<cstdlib>      
#include<iomanip>      
#include<vector>      
#include<list>         
#include<queue>    
#include<algorithm>    
using namespace std;
int  main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a<=m) sum++;
			else if(a>m) sum+=2;
			
		}
		printf("%d\n",sum);
	}
	return 0;
}