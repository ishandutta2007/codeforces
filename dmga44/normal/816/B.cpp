#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
#define MAXN 200005

int abi[MAXN],acu[MAXN];

void update(int pos,int v)
{
    while(pos>0)
    {
        abi[pos]+=v;
        pos-=(pos&-pos);
    }
}

int query(int pos)
{
    int res=0;
    while(pos<MAXN)
    {
        res+=abi[pos];
        pos+=(pos&-pos);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,q,ai,bi;
    cin >> n >> k >> q;
    for(int i=0;i<n;i++)
    {
        cin >> ai >> bi;
        update(ai-1,-1);
        update(bi,1);
    }

    for(int i=1;i<MAXN;i++)
    {
        acu[i]=acu[i-1];
        if(query(i)>=k)
            acu[i]++;
    }

    for(int i=0;i<q;i++)
    {
        cin >> ai >> bi;
        db(acu[bi]-acu[ai-1])
    }
    return 0;
}