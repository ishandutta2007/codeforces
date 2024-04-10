#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 300005

int mk[2][MAXN],d1[MAXN],d2[MAXN],c[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin >> n >> q;
    int cant=0;
    for(int i=0;i<q;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        int add=0;
        if(mk[u][v])
        {
            mk[u][v]=0;
            add=-1;
        }
        else
        {
            mk[u][v]=1;
            add=1;
        }

        int d11=-1;
        if((!u && v) || (u))
            d11=v+u;
        int d22=-1;
        if((!u && v<n-2) || (u && v>1))
            d22=v-u;
        int cc=-1;
        if(v && v<n-1)
            cc=v;

        if(d11!=-1)
        {
            if(d1[d11]==2)
                cant--;
            d1[d11]+=add;
            if(d1[d11]==2)
                cant++;
        }
        if(d22!=-1)
        {
            if(d2[d22]==2)
                cant--;
            d2[d22]+=add;
            if(d2[d22]==2)
                cant++;
        }
        if(cc!=-1)
        {
            if(c[cc]==2)
                cant--;
            c[cc]+=add;
            if(c[cc]==2)
                cant++;
        }

        if(cant)
            db("No")
        else
            db("Yes")
    }

    return 0;
}