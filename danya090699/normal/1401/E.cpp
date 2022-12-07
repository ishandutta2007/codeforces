#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, mx=1e6;
vector <int> in[sz], out[sz];
struct el
{
    int y, l, r;
    bool operator < (el t)
    {
        return y<t.y;
    }
};
int fen[sz];
void cha(int p, int va)
{
    while(p<sz)
    {
        fen[p]+=va, p=p|(p+1);
    }
}
int que(int p)
{
    int re=0;
    while(p>=0)
    {
        re+=fen[p], p=(p&(p+1))-1;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m2;
    cin>>n>>m2;
    el ar[n+1];
    ar[0]={mx, 0, mx};
    for(int a=1; a<=n; a++)
    {
        scanf("%d%d%d", &ar[a].y, &ar[a].l, &ar[a].r);
    }
    sort(ar, ar+n+1);
    int m=0;
    for(int a=0; a<m2; a++)
    {
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        if(l==0)
        {
            cha(x, 1), m++;
            out[r].push_back(x);
        }
        else in[l].push_back(x);
    }

    long long an=0;
    set <int> se;
    int y=0;
    for(int a=0; a<=n; a++)
    {
        for(int b=y; b<ar[a].y; b++)
        {
            for(int c=0; c<out[b].size(); c++) cha(out[b][c], -1), m--;
        }


            if(ar[a].l==0 and ar[a].r==mx) an+=m+1;
            else if(ar[a].l==0) an+=que(ar[a].r);
            else an+=m-que(ar[a].l-1);

        for(int b=y+1; b<=ar[a].y; b++)
        {
            for(int c=0; c<in[b].size(); c++) se.insert(in[b][c]);
        }
        if(ar[a].l==0)
        {
            while(se.size())
            {
                int p=*se.begin();
                if(p<=ar[a].r)
                {
                    se.erase(se.begin());
                    cha(p, 1), m++;
                }
                else break;
            }
        }
        else
        {
            while(se.size())
            {
                auto it=se.end();
                it--;
                int p=*it;
                if(p>=ar[a].l)
                {
                    se.erase(it);
                    cha(p, 1), m++;
                }
                else break;
            }
        }
        y=ar[a].y;

        //cout<<an<<"\n";
    }
    cout<<an;
}