#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
char s[sz];
int c[20][sz], p[sz], st[sz], N, step;
bool sufcmp(int x, int y)
{
    if (c[step][x] != c[step][y]) return c[step][x] < c[step][y];
    x+=(1<<step); y += (1<<step);
    if(x>=N) x-=N;
    if(y>=N) y-=N;
    return c[step][x] < c[step][y];
}
void build2(int n)//n*(logn)^2, small constant
{
    N=n;
    for(int a=0; a<N; a++) p[a]=a, c[0][a]=s[a]-'a';
    for(step=0; (1<<step)<N; step++)
    {
        sort(p, p+N, sufcmp);
        c[step+1][p[0]]=0;
        for(int a=1; a<N; a++) c[step+1][p[a]]=c[step+1][p[a-1]]+sufcmp(p[a-1], p[a]);
    }
    for(int i=0; i<=step; i++)
    {
        for(int a=(1<<i); a<min(N+1, (1<<(i+1))); a++) st[a]=i;
    }
}
int lcp(int p1, int p2)
{
    int re=0;
    for(int i=step; i>=0; i--)
    {
        if(c[i][p1]==c[i][p2]) p1+=(1<<i), p2+=(1<<i), re+=(1<<i);
    }
    return re;
}
bool comp(pair <int, int> a, pair <int, int> b)
{
    if(c[step][a.first]!=c[step][b.first]) return c[step][a.first]<c[step][b.first];
    else return a.second<b.second;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    scanf("%s", s);
    s[n]='#';
    build2(n+1);
    for(int a=0; a<q; a++)
    {
        int m[2];
        scanf("%d%d", &m[0], &m[1]);
        vector <pair <int, int> > sp;
        for(int i=0; i<2; i++)
        {
            for(int b=0; b<m[i]; b++)
            {
                int p;
                scanf("%d", &p);
                sp.push_back({p-1, i});
            }
        }
        sort(sp.begin(), sp.end(), comp);
        long long an=0;
        for(int i=0; i<2; i++)
        {
            long long cu=0;
            vector <pair <int, int> > sta;
            for(int b=0; b<sp.size(); b++)
            {
                int p=sp[b].first, ty=sp[b].second;
                int va=n-p;
                if(b) va=lcp(p, sp[b-1].first);
                pair <int, int> add={va, 0};
                while(sta.size())
                {
                    if(sta.back().first>=va)
                    {
                        cu-=1ll*sta.back().first*sta.back().second;
                        add.second+=sta.back().second;
                        sta.pop_back();
                    }
                    else break;
                }
                if(add.second)
                {
                    cu+=1ll*add.first*add.second;
                    sta.push_back(add);
                }
                if(ty==0) sta.push_back({n-p, 1}), cu+=n-p;
                else an+=cu;
            }
            reverse(sp.begin(), sp.end());
        }
        printf("%lld\n", an);
    }
}