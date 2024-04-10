#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int LEVELS=9;
    const int BUCKET=(1<<LEVELS);
    int n;
    cin >> n;
    const int N=((n+BUCKET-1)/BUCKET)*BUCKET;
    array<vector<int>,LEVELS+1> jump,idx;
    jump.fill(vector<int>(N,-1));
    idx.fill(vector<int>(N,-1));
    for(int i=0;i<N;i++)
    {
        int a=0;
        if(i<n) cin >> a;
        jump[0][i]=i-a;
        idx[0][i]=i;
    }
    vector<int> ini(N,-1);
    auto st_merge=[&](int lvl,int l)
    {
        int m=l+(1<<(lvl-1));
        int r=l+(1<<lvl);
        int x=l;
        int y=m;
        for(int z=l;z<r;z++)
        {
            if(x<m&&(y==r||jump[lvl-1][x]+(y-m)<jump[lvl-1][y]))
            {
                jump[lvl][z]=jump[lvl-1][x]+(y-m);
                idx[lvl][z]=idx[lvl-1][x];
                x++;
            }
            else
            {
                jump[lvl][z]=jump[lvl-1][y];
                idx[lvl][z]=idx[lvl-1][y];
                y++;
            }
        }
    };
    auto update_ini=[&](int id)
    {
        for(int i=(id<<LEVELS);i<((id+1)<<LEVELS);i++) ini[idx[LEVELS][i]]=jump[LEVELS][i];
    };
    for(int lvl=1;lvl<=LEVELS;lvl++)
    {
        for(int i=0;i<N;i+=(1<<lvl)) st_merge(lvl,i);
    }
    for(int id=0;(id<<LEVELS)<N;id++) update_ini(id);
    auto update=[&](int i)
    {
        int a;
        cin >> a;
        jump[0][i]=i-a;
        for(int lvl=1;lvl<=LEVELS;lvl++)
        {
            i=((i>>lvl)<<lvl);
            st_merge(lvl,i);
        }
        update_ini(i>>LEVELS);
    };
    auto bucket_jump=[&](int id,int &x)
    {
        int l=-1,r=BUCKET;
        int i=(id<<LEVELS);
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(jump[LEVELS][i+m]<=x+m) l=m;
            else r=m;
        }
        x+=(l+1);
    };
    auto query=[&](int x)->int
    {
        int id=(x>>LEVELS);
        x=ini[x];
        for(id++;(id<<LEVELS)<N;id++) bucket_jump(id,x);
        return x;
    };
    int q;
    cin >> q;
    while(q--)
    {
        int t,i;
        cin >> t >> i;
        i--;
        if(t==1) update(i);
        else cout << query(i)+1 << "\n";
    }
    return 0;
}