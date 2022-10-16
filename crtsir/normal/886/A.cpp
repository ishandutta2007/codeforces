#include<iostream>
using namespace std;
int main(){
	int a[6];
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
	for(int i=0;i<4;i++)
		for(int j=i+1;j<5;j++)
			for(int ij=j+1;ij<6;ij++)
				if((a[i]+a[j]+a[ij])*2==a[0]+a[1]+a[2]+a[3]+a[4]+a[5])
				{
					cout<<"YES";
					return 0;
				}
	cout<<"NO";
}