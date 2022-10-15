#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n,q,l;
int v[N];
bool is[N];

int st[N];
int dr[N];
int comp;

inline void upd(int poz)
{
    is[poz]=1;
    if(is[poz-1] && is[poz+1])
    {
        comp--;
    }
    if(is[poz-1]==0 && is[poz+1]==0)
    {
        comp++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q>>l;
    for(int i=1;i<=n;i++)
    {
        st[i]=dr[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]>l)
        {
            upd(i);
        }
    }
    while(q--)
    {
        int t;
        cin>>t;
        if(t==0)
        {
            cout<<comp<<"\n";
        }
        else
        {
            int i,x;
            cin>>i>>x;
            if(v[i]>l)
            {
                continue;
            }
            if(v[i]<=l && v[i]+x>l)
            {
                upd(i);
            }
            v[i]+=x;
        }
    }
    return 0;
}
/**

**/