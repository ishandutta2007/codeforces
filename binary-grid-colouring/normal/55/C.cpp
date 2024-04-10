#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()  
{  
    int n,m,k;
    cin>>n>>m>>k;
    if(k==0)return 0*printf("NO\n");
    else
    {
    	int flag=0;
    	for(int i=0;i<k;i++)
    	{
    		int a,b;
    		cin>>a>>b;
    		if(a<=5 || a>=n-4 || b<=5 || b>=m-4)flag=1;
		}
		printf("%s\n",flag?"YES":"NO");
	}
    return 0;  
}