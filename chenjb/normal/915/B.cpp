#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
int main()
{
	int n,pos,l,r;
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	int ans=0;
	if (l==1&&r==n)ans=0;
  	else 
  	if (l==1)ans=abs(pos-r)+1;
  	else 
  	if (r==n)ans=abs(pos-l)+1;
    else 
    {
    	ans=min(abs(pos-l)+abs(r-l),abs(pos-r)+abs(r-l));
    	ans+=2;
    }
    cout<<ans<<endl;
}