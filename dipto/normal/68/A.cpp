#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define INF 2000000000
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REV(i,x,n) for(int i=x;i>=n;i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define LL long long
#define test int T;scanf("%d",&T);while(T--)

int main()
{
int a,b,p1,p2,p3,p4,x;

cin>>p1>>p2>>p3>>p4>>a>>b;
x=min( min(p1,p2), min(p3,p4) );

//printf("%d\n", x>a ? (x-a) :0);

if(x<=a) printf("0");
else
    if(x>b) printf("%d",b-a+1);
    else printf("%d",x-a);

//getchar();
//getchar();

return 0;
}