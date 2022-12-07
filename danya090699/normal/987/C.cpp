#include <bits/stdc++.h>
using namespace std;
const int inf=4e8;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=inf;
    cin>>n;
    int si[n], va[n];
    for(int a=0; a<n; a++) cin>>si[a];
    for(int a=0; a<n; a++) cin>>va[a];
    for(int a=0; a<n; a++)
    {
        int bel=inf, ber=inf;
        for(int b=0; b<a; b++) if(si[b]<si[a]) bel=min(bel, va[b]);
        for(int b=a+1; b<n; b++) if(si[b]>si[a]) ber=min(ber, va[b]);
        an=min(an, bel+ber+va[a]);
    }
    if(an<inf) cout<<an;
    else cout<<-1;
}