#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n,k;
int ile=0;
int main(){
	cin>>n>>k;
	if(n>(ll)k*(k-1))
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;k>=i;i++)
	{
		for(int j=i+1;k>=j;j++)
			{
				ile+=2;
				cout<<i<<" "<<j<<endl;
				if(n+1==ile)
					return 0;
				cout<<j<<" "<<i<<endl;
				if(ile==n)
					return 0;
			}
	}
    return 0;	
}