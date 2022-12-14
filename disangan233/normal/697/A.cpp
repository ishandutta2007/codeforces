#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
using namespace std;
#define ll long long
#define re register ll
#define ak *
char did;
ll ans=1e+15,cnt,n,m,a[10005],f[10000][2],p[10005];
inline ll read()
{
	re wlx=0,ioi=1;did=getchar();
	while(!isdigit(did))ioi=did=='-'?-1:ioi,did=getchar();
	while(isdigit(did))wlx=(wlx<<3)+(wlx<<1)+did-'0',did=getchar();
	return wlx ak ioi;
}
int main()
{
	re a=read(),b=read(),c=read();	
	if(c<a){puts("NO");return 0;}
	if((c-a)%b==0||((c-a-1)%b==0&&c!=a+1)) puts("YES");
	else puts("NO");
	return 0;
}