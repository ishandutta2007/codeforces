#include<iostream>
using namespace std;
int main()
{
	int max1=0,max2=0,min1=10000,min2=100000,a,b;
	cin>>a>>b;
	char c[a+1][b+1];
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			cin>>c[i][j];
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			if(c[i][j]=='*'){
				if(i>max1)max1=i;
				if(i<min1)min1=i;
				if(j>max2)max2=j;
				if(j<min2)min2=j;
			}
	for(int i=min1;i<=max1;i++){
		for(int j=min2;j<=max2;j++)
			cout<<c[i][j];
		cout<<endl;
	}
}