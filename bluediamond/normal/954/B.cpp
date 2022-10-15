#include <bits/stdc++.h>

using namespace std;

int n;
int v[105];
char ch;

int main()
{
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        v[i]=ch-'a';
    }
    int best=n;
    for(int i=1;2*i<=n;i++)
    {
        bool ok=1;
        for(int j=1;j<=i;j++)
            if(v[j]!=v[j+i] || j+i>n)
            {
                ok=0;
                break;
            }
        if(ok==1)
            best=min(best,i+1+n-2*i);
    }cout<<best;
    return 0;
}
/**
**/