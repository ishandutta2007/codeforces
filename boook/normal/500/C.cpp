#include<bits/stdc++.h>
using namespace std;
#define MAX 1010 
int n,m,x[MAX],use[MAX],q[MAX],xx[MAX];
int main(){
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(use,0,sizeof use);
		for(int i=0;i<n;i++) scanf("%d",&x[i]);
		for(int i=0;i<m;i++) scanf("%d",&q[i]);
		int po=0;
		for(int i=0;i<m;i++)
		{
			if(!use[ q[i]-1 ] )
				xx[po++] = q[i]-1 , use[ q[i]-1 ] = 1;
		}
		
		/*for(int i=0;i<po;i++)
			cout<<xx[i]<<" ";cout<<endl;//*/
		
		
		int ans = 0 , w , j;
		for(int i=0;i<m;i++)
		{
			w = q[i]-1 ;
			
			for( j = 0 ; ; j++ )
			{
				if( xx[j] == w ) break; 
				ans += x[ xx[j] ];
			}
			for(; j > 0 ; j--)
			{
				xx[j] = xx[j-1];
			}
			xx[0]= w ;
			
		/*	cout<< " W" <<w <<"  " << ans<<endl; 
			for(int i=0;i<po;i++)
			cout<<xx[i]<<" ";cout<<endl; //*/
		}
		cout << ans <<endl; 
			
	}
	return 0;
}