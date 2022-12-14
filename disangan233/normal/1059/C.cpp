#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,m,ak=1;
int main()
{
    cin>>n;
    while(n)
    {
    	if(n==3)return cout<<ak<<" "<<ak<<" "<<ak*3,0;
    	for(re i=1;i<=ceil(n/2.0);i++) printf("%d ",ak);
    	n/=2;ak*=2;
	}
    return 0;
}