#include<bits/stdc++.h>
using namespace std;
int w[3]={1,2,4};
int f[20010];
int A[3];
int n,a,b,c; 
int main()
{
	cin>>n>>a>>b>>c;
	n = n*2;
	f[0] = 1;
	A[0] = a;
	A[1] = b;
	A[2] = c;
	for(int i=0;i<3;i++)
	{
		for(int j=n;j>=1;--j)
		{
			for(int k=1;k<=A[i];k++)
			{
				if(j - k*w[i]>=0){
					f[j] += f[j - k*w[i]];
				}
			}
		}
	}
	cout<<f[n]<<endl;
	return 0;
}