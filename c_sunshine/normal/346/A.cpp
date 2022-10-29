#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[105];;
int gcd(int x,int y)
{return y?gcd(y,x%y):x;}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int g=a[1],s=0;
    for(int i=2;i<=n;i++)g=gcd(g,a[i]);
    for(int i=1;i<=n;i++)s=max(s,a[i]/g);
    printf("%s\n",(s-n&1)?"Alice":"Bob");
    return 0;
}