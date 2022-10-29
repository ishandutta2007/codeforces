#include <iostream>
using namespace std;

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	int a=n*m-2*(k-1);
	int a1=1,a2=1;
	for(int i=1;i<=(k-1);i++)
	{
		cout<<"2 "<<a1<<" "<<a2;
		if(a1%2==1)
		a2++;
		else
		a2--;
		if(a2==m+1){
		a1++;
	            a2--;
		}
		if(a2==0)
		{
			a1++;
			a2++;
		}
		cout<<" "<<a1<< " "<<a2<<endl;
		if(a1%2==1)
		a2++;
		else
		a2--;
		if(a2==m+1){
		a1++;
	            a2--;
		}
		if(a2==0)
		{
			a1++;
			a2++;
		}
	}
	cout<<a<<" ";
	for(int i=1;i<=a;i++)
	{
		cout<<a1<<" "<<a2<<" ";
		if(a1%2==1)
		a2++;
		else
		a2--;
		if(a2==m+1){
		a1++;
	            a2--;
		}
		if(a2==0)
		{
			a1++;
			a2++;
		}
	}
	
	return 0;
}