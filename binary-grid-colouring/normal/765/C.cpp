#include<bits/stdc++.h>
using namespace std;
//(a,b)(x,k)(k,x) 
int main()
{
    int a,b,k;
    cin>>k>>a>>b;
    if(a<k&&b%k!=0)return 0*puts("-1");
    if(b<k&&a%k!=0)return 0*puts("-1");
    cout<<a/k+b/k<<endl;
	return 0;
}