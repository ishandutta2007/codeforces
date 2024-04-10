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
	long int n,i;
	cin>>n;
	long int count=0;
	long int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(a[i]%2==0)count++;
	}
	if(count !=0 && count!=n)
	sort(a,a+n);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	
	return 0;
}