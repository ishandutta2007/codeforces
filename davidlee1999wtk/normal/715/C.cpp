#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int n, P, cf10[N], inv10[N];
LL ans = 0;
vector<pii> G[N];
int ksm(int a, int b)
{
    if (P == 1)
        return 0;
    int c = 1, d = a;
    while (b)
    {
        if(b&1)
            c = (LL)c * d % P;
        d = (LL)d*d % P;
        b >>= 1;
    }
    return c;
}
map<int, int> mp_fr;
int sz[N], vis[N];//vis 
int get_root(int x, int qnt,int fa)
{
    int i, v, rt = -1, tmp, mx = 0;
    sz[x] = 1;
    for (i = 0; i < G[x].size(); i++)
    {
        v = G[x][i].fi;
        if (!vis[v] && v != fa)
        {
            tmp = get_root(v, qnt, x);
            if (tmp != -1)
                rt = tmp;
            mx = max(mx, sz[v]);
            sz[x] += sz[v];
        }
    }
    if (mx <= qnt / 2 && qnt - sz[x] <= qnt / 2)
        return x;
    else return rt;
}

int get_size(int x, int fa)
{
    int i, v;
    sz[x] = 1;
    for (i = 0; i < G[x].size(); i++)
    {
        v = G[x][i].fi;
        if (!vis[v] && v != fa)
            sz[x] += get_size(v, x);
    }
    return sz[x];
}

void dfs(int x, int fa, int dep, int dn_val, int up_val, vector<int> &up, vector<int> &dn)
{
    int i, v;
    up.push_back(up_val);
    dn.push_back(dn_val);
    //debug(x);
    //debug(dn_val);
    //debug((LL)(-dn_val + P)*inv10[dep] % P);
    ans += mp_fr[(LL)(-dn_val + P)*inv10[dep]%P];//
    for (i = 0; i < G[x].size(); i++)
    {
        v = G[x][i].first;
        if (!vis[v] && v != fa)
            dfs(v, x, dep + 1, ((LL)dn_val * 10 + G[x][i].second) % P, (up_val + (LL)cf10[dep] * G[x][i].second) % P, up, dn);
    }
}

void Calc(int rt)
{
    int i, v, j;
    for (i = 0; i < G[rt].size(); i++)
    {
        v = G[rt][i].first;
        if (!vis[v])
        {
            vector<int> up;
            vector<int> dn;
            dfs(v, rt, 1, G[rt][i].se, G[rt][i].se, up, dn);
            for (j = 0; j < up.size(); j++)
            {
                mp_fr[up[j]]++;
                if (up[j] == 0)//
                    ans++;
            }
            for (j = 0; j < dn.size(); j++)
            {
                if (dn[j] == 0)
                    ans++;
            }
        }
    }
    mp_fr.clear();
    for (i = G[rt].size() - 1; i >= 0; i--)
    {
        v = G[rt][i].first;
        if (!vis[v])
        {
            vector<int> up;
            vector<int> dn;
            dfs(v, rt, 1, G[rt][i].se, G[rt][i].se, up, dn);
            for (j = 0; j < up.size(); j++)
                mp_fr[up[j]]++;
        }
    }
}

void Divide_and_Conquer(int x, int qnt)
{
    int rt = get_root(x, qnt, -1), i, v;
    //debug(x);
    //debug(rt);
    mp_fr.clear();
    vis[rt] = 1;
    Calc(rt);
    //debug(ans);
    for (i = 0; i < G[rt].size(); i++)
    {
        v = G[rt][i].first;
        if (!vis[v])
            Divide_and_Conquer(v, get_size(v, rt));
    }
}

int phi(int x)
{
    int ans = x, i;
    for (i = 2; i*i <= x; i++)
        if (x%i == 0)
        {
            ans = ans / i*(i - 1);
            while (x%i == 0) x /= i;
        }
    if (x>1) ans = ans / x*(x - 1);
    return ans;
}

int main()
{
    int i, a, b, c;
    cin >> n >> P;
    cf10[0] = inv10[0] = 1;
    for (i = 1; i < n; i++)
    {
        cf10[i] = (LL)cf10[i - 1] * 10 % P;
        inv10[i] = ksm(cf10[i], phi(P)-1 );
        //debug(cf10[i]);
        //debug(inv10[i]);
        scanf("%d%d%d", &a, &b, &c);
        a++, b++;
        c %= P;
        G[a].push_back(MP(b, c));
        G[b].push_back(MP(a, c));
    }
    Divide_and_Conquer(1, n);
    cout << ans << endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/