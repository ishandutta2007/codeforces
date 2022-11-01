#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double prob[18][18];
double f[1<<18];
int cnt;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cin>>prob[i][j];
		}
	}
	f[(1<<n)-1] = 1;// 1 
	for(int i=(1<<n)-1;i>0;--i)// 
	{
		cnt = 0;
		for(int j=0;j<n;j++) //
		{
			if(i & (1<<j))//j
			{
				cnt++;
			}
		}
		for(int j=0;j<n;j++)//jk  
		{
			if((i&(1<<j))==0)continue;//j 
			
			for(int k=j+1;k<n;k++) 
			{
				if((i&(1<<k))==0)continue;//k 
				//f(jk) = f(jk) * f(jk)* f(jk) 
				f[i - (1<<k)] += f[i] * prob[j][k] * 1.0 / (cnt * (cnt - 1) / 2);
				f[i - (1<<j)] += f[i] * prob[k][j] * 1.0 / (cnt * (cnt - 1) / 2);
			}
		}
	}
	
	for(int i=0;i<n-1;i++)
	{
		printf("%.6f ",f[1<<i]);//i
	}
	printf("%.6f\n",f[1<<(n-1)]);
    return 0;
}