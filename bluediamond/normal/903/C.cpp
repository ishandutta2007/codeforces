#include<bits/stdc++.h>
using namespace std;
const int nmax=5000;
int n;
int v[nmax+5];
int aux[nmax+5];
int s=0;
void nxt()
{
    int y=0;
    for(int i=1;i<=n;i++)
        if(v[i]==v[i-1])
            aux[++y]=v[i];
    n=y;
    for(int i=1;i<=n;i++)
        v[i]=aux[i];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    while(n)
    {
        nxt();
        s++;
    }
    cout<<s;
    return 0;
}
/**

**/