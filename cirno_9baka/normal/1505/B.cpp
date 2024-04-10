#include<bits/stdc++.h>
using namespace std;
int f[105];
int i,vis[105],s,a;
char c[105];
int main()
{
    scanf("%d",&a);
    while(a>=10)
    {
    	s=0;
    	while(a)
    	{
    		s+=a%10;
    		a/=10;
    	}
    	a=s;
	}
	cout<<a;
}