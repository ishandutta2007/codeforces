#include <bits/stdc++.h>

using namespace std;

const int nmax=100000;
int n,v[nmax+5],ans,total;

int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    for(int i=1;i<n;i++)
        ans=cmmdc(ans,v[i+1]-v[i]);
    for(int i=1;i<n;i++)
        total+=(v[i+1]-v[i]-1)/ans;
    printf("%d",total);
    return 0;
}