#include <bits/stdc++.h>

using namespace std;

const int nmax=100000;
int n,v[nmax+5];
char ch;

int T(int ind,int tip)
{
    if(tip==1)
        return ind%2;
    return 1-ind%2;
}
int main()
{
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        if(ch=='r')
            v[i]=1;
    }
    int nebune0,nebune1;
    int cost1=0,cost2=0;
    /// 1
    nebune0=nebune1=0;
    for(int i=1;i<=n;i++)
        if(v[i]!=T(i,1))
        {
            if(v[i]==0)
                nebune0++;
            else
                nebune1++;
        }
    cost1=max(nebune0,nebune1);
    /// 2
    nebune0=nebune1=0;
    for(int i=1;i<=n;i++)
        if(v[i]!=T(i,2))
        {
            if(v[i]==0)
                nebune0++;
            else
                nebune1++;
        }
    cost2=max(nebune0,nebune1);
    cout<<min(cost1,cost2);
    return 0;
}
/**
**/