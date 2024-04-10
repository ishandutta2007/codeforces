#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
int a,b;
int maxi,mini;
const int inf=1e9+7;
int main(){
	cin>>n;
	maxi=-inf;
	mini=inf;
	int x=0;
	for(int i=1;n>=i;i++)
	{
		cin>>a>>b;
		if(b==1)
			maxi=max(maxi,1900-x);
		else
			mini=min(mini,1899-x);
		x+=a;
	}
	if(mini==inf)
		cout<<"Infinity";
	else if(mini<maxi)
		cout<<"Impossible";
	else
		cout<<mini+x;
		
    return 0;	
}