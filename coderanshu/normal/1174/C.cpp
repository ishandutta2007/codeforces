#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	long int n,i,f,j;
	cin>>n;
	int a[n+1],k=1;
	memset(a,0,sizeof(a));
	for(i=2;i<=n;i++)
	{
	    f=0;
	    for(j=i;j<=n;j+=i)
	    {
	        if(!a[j])
	        {
	        a[j]=k;
	        f=1;
	        }
	    }
	    if(f)
	    k++;
	}

	for(i=2;i<=n;i++)
	cout<<a[i]<<" ";
	
	
	return 0;
}