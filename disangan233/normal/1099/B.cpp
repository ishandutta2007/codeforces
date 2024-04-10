#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,minn=121311232;cin>>n;
	for(int i=sqrt(n);i>=1;i--) minn=min(minn,((int)ceil(1.0*n/i))+i);
	return cout<<minn,0;
}