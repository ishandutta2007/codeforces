#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    n--;
    int fl[sz];
    for(int a=0; a<sz; a++) fl[a]=-1;
    for(int a=0; a<m; a++)
    {
        int k, f;
        cin>>k>>f;
        fl[k-1]=f-1;
    }
    int an=0;
    for(int a=1; a<sz; a++)
    {
        int ok=1;
        for(int b=0; b<sz; b++)
        {
            if(fl[b]!=-1)
            {
                if(b/a!=fl[b]) ok=0;
            }
        }
        if(ok)
        {
            int nu=n/a+1;
            if(an==0) an=nu;
            else if(an!=nu) an=-1;
        }
    }
    cout<<an;
}