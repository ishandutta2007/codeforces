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
#define sld(x) scanf("%Lf",&x)
#define LL long long
#define test int T;scanf("%d",&T);while(T--)
#define pb push_back
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()
#define mp make_pair
#define fi first
#define se second
#define LD long double
#define dist(x1,y1,x2,y2) sqrtl( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) )

int cal(char *a)
    {
    int cnt=0;
    for(int i=0;a[i]!='\0';i++)
    if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
    cnt++;
    return cnt;
    
    }

int main()
{
char a[10]="VIBGYOR";
int N;
si(N);
N-=3;
FOR(i,0,N-1)
cout<<a[i%4];
cout<<"YOR";


return 0;
}