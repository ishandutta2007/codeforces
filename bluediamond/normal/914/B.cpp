#include <bits/stdc++.h>
using namespace std;
const int nmax=100000;
int n,v[nmax+5],nr;
struct data
{
    int val,ap;
};
data sol[nmax+5]; int y;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++)
    {
        if(v[i]!=v[i-1])
            sol[++y].val=v[i];
        sol[y].ap++;
    }
    reverse(sol+1,sol+y+1);
    for(int i=1;i<=n;i++)
        if(sol[i].ap%2==1)
        {
            cout<<"Conan";
            return 0;
        }
    cout<<"Agasa";
    return 0;
}
/**
Conan
Agasa
**/