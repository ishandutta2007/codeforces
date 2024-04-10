#include<bits/stdc++.h>
using namespace std;
long long ans[1000100];
int main()
{
//	cerr<<(-9)/8<<endl;
	long long p ,k ,n ,sum;
	long long temp;
	int i;
	cin>>p>>k;
	sum=p; n=0;		
	while (1)
	{
		if (sum>=0&&sum<k)break;	
		if (sum<0)
		{
			temp=(-sum/k)+1;
			ans[n]=(temp*k)+sum;
			sum=temp;
			if (ans[n]==k)
			{
				ans[n]-=k;
				sum--;	
			}
			n++;				
		}
		else
		{
			temp=sum/k;
			ans[n]=(-temp*k)+sum;
			sum=-temp;
			n++;
		}
	}
	ans[n]=sum;
	n++;
	printf("%I64d\n" ,n);
	for (i=0 ; i<n ; i++)
		printf("%I64d " ,ans[i]);
	
	return 0;
}