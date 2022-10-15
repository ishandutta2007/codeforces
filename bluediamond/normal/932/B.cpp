#include <bits/stdc++.h>
using namespace std;
const int nmax=1e6;
int G[nmax+5];
int cate[15][nmax+5];
int f(int key)
{
    int ans=1;
    while(key>0)
    {
        if(key%10)
            ans=ans*(key%10);
        key/=10;
    }
    return ans;
}
void slove(int key)
{
    if(G[key]!=0)
        return;
    int X=f(key);
    slove(X);
    G[key]=G[X];
}
void build()
{
    for(int i=1;i<=9;i++)
        G[i]=i;
    for(int i=10;i<=nmax;i++)
        slove(i);
    for(int i=1;i<=nmax;i++)
        cate[G[i]][i]++;
    for(int i=1;i<=nmax;i++)
        for(int k=1;k<=9;k++)
            cate[k][i]+=cate[k][i-1];
}
int main()
{
    build();
    int q;
    cin>>q;
    while(q--)
    {
        int st,dr,k;
        cin>>st>>dr>>k;
        cout<<cate[k][dr]-cate[k][st-1]<<"\n";
    }
    return 0;
}