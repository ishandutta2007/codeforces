#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[30];

int main()
{	
    int n,m;
	int ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    for(int j=0;j<n+1;j++)
    {
    	for(int i=0;i<j;i++)
    	{
    		for(int l=0;l<m+1;l++)
    		{
    			for(int k=0;k<l;k++)
    			{
    				bool free =true;
    				for(int x=i;x<j;x++)
    				{
    					for(int y=k;y<l;y++)
    					{
    						if(a[x][y]=='1'){
    							free = false;
							} 
						}
					}
					if(free)
					{
						ans = max(ans,2 * ((j-i)+(l-k)));
					}
				}
			}
		}
	}   
    cout<<ans<<endl;
    return 0;
}