#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <ctime>
#include <map>
#include <queue>
#include <set>
using namespace std;
 
int k,n,maxb,t,b[100005],f[20000005];
int main()
{
	scanf("%d%d%d%d",&k,&n,&maxb,&t);
	t=min(t,n);
    t=min(t,maxb);
    while (k--)
    {
    	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        memset(f,0,sizeof(f));
    	for (int i=1;i<=t;i++)
    	 for (int j=1;j<=n;j++)
    	 {
    	 	f[b[j]]=f[b[j]-1]+1;
    	 	for (int kk=b[j]+1;kk<=maxb && f[kk]<f[b[j]];f[kk]=f[b[j]],kk++);
    	 }
        printf("%d\n",f[maxb]);
    }
	return 0;
}