#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	long long int ar[n][2];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i][0];
		cin>>ar[i][1];
	}
	long long int min=0;
	for(int i=0;i<n;i++)
	{
		min=2000000000;
		for(int j=i;j<n;j++)
		{
			if(ar[j][0]<min)
			{
				min=ar[j][0];
				long long int temp=ar[j][0];
                                                ar[j][0]=ar[i][0];
                                                ar[i][0]=temp;
                                                temp=ar[j][1];
                                                ar[j][1]=ar[i][1];
                                                ar[i][1]=temp;
			}
		}
	}
	long long int ans=ar[0][1];
	long long int last=ar[0][0];
	for(int i=1;i<n;i++)
	{
		if(last==ar[i][0])
		{
			ans=(ans>ar[i][1])?ans:ar[i][1];
		}
		else if(ar[i][1]<ans)
		ans=ar[i][0];
		else
		ans=ar[i][1];
		last=ar[i][0];
	}
	cout<<ans;
	return 0;
}