#include<bits/stdc++.h>
using namespace std;
char a[8][8];
int main()
{
	int sum1=0,sum2=0;
	for(int i=0;i<8;i++){
		int count=0;
		for(int j=0;j<8;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='B'){
				count++;
			}
		}
		if(count==8)
		{
			sum1++;
		}
		else sum2=count;
	}
	cout<<sum1+sum2<<endl;
	
	return 0;
}