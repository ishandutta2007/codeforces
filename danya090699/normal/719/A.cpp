#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int a=0; a<n; a++) cin>>ar[a];
	if(ar[n-1]==0) cout<<"UP";
	else if(ar[n-1]==15) cout<<"DOWN";
	else
	{
		if(n==1) cout<<-1;
		else
		{
			if(ar[n-2]<ar[n-1]) cout<<"UP";
			else cout<<"DOWN";
		}
	}
}