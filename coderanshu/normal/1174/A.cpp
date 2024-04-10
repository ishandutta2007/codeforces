#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argarr[])
{
	ios_base::sync_with_stdio(0);
	int n,i;
	cin>>n;
	long int a[2*n];
	for(i=0;i<2*n;i++)
	cin>>a[i];
	sort(a,a+2*n);
	if(a[2*n-1]==a[0])
	cout<<-1;
	else 
	{
	    for(i=0;i<2*n;i++)
	    cout<<a[i]<<" ";
	}
	
	return 0;
}