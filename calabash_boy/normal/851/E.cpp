#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9 + 5;
const int MAXN = 100007;
const int MOD = 30021;
const double eps = 1e-8;
const double PI = acos(-1.0);

map<int, int> SG,num;

int getSG(int x)
{
    if (x == 0)
        return 0;
    if (SG.count(x))
        return SG[x];
    map<int, int> vis;
    int p = x;
    int t=0;
    while (p)//
        p /= 2,t++;
    for (int k = 1; k <= t; k++)
        vis[getSG((x >> k) | (x&((1 << k-1) - 1)))] = 1;//
    for (int i = 0;; i++)
        if (!vis[i])
            return SG[x]=i;
}

int prime[MAXN], primesize;
bool isprime[MAXN];
void getlist(int listsize)//
{
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= listsize; i++)
    {
        if (isprime[i])prime[++primesize] = i;
        for (int j = 1; j <= primesize&&i*prime[j] <= listsize; j++)
        {
            isprime[i*prime[j]] = false;
            if (i%prime[j] == 0)break;
        }
    }
}

void solve()//x
{
    int t,x;
    scanf("%d", &x);
    for (int i = 1; prime[i]*prime[i] <= x; i++)
    {
        t = 0;
        while (x%prime[i] == 0)
            x /= prime[i], t++;//xp
        if(t!=0)
            num[prime[i]] = num[prime[i]] | 1 << (t - 1);//p^tt
    }
    if (x != 1)
        num[x] = num[x] | 1;
}

int main()
{
    getlist(100005);
    int n;
    int x;
    int ans = 0;
    scanf("%d", &n);
    while (n--)
        solve();
    map<int, int>::iterator it;
    for (it = num.begin(); it != num.end(); it++)
        ans ^= getSG(it->second);
    if (ans == 0)
        printf("Arpa\n");
    else
        printf("Mojtaba\n");
}