#include <bits/stdc++.h>

using namespace std;

const int nmax=100;
int n,d;
int v[nmax+5],dif[nmax+5];
int best;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);
    best=n-1;
    for(int st=1;st<=n;st++)
        for(int dr=st+1;dr<=n;dr++)
        {
            if(v[dr]-v[st]<=d)
                best=min(best,st-1+n-dr);
        }
    cout<<best;
    return 0;
}
/**


**/