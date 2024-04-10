#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int K = 47;

int n, k;
bool now[K];
ll sp[K];
map<string, int>has;
int skrip = 0;

int gt (string s)
{
    if (has[s] == 0)
    {
        skrip++;
        has[s] = skrip;
    }
    return has[s];
}

bool kek[K][K];

ll func (ll mask)
{
    return mask & (-mask);
}

map<ll, int>dp;
map<ll, int>lg;

ll papa;
ll typ;

void calc (ll mask)
{
    // cout<<typ<<" "<<papa<<"->"<<mask<<"\n";
    if (mask == 0) return;
    if (dp[mask] > 0)
    {
        return;
    }
    ll s = func (mask);
    if (mask == s)
    {
        dp[mask] = 1;
        return;
    }
    int nod = lg[s];
    /// take nod than do not take vecini
    // cout<<mask<<" , "<<s<<" "<<sp[nod+1]<<" "<<"\n";
    typ = 1;
    papa = mask;
    calc (mask & sp[nod + 1]);
    dp[mask] = dp[mask & sp[nod + 1]] + 1;
    /// do not take nod
    typ = 2;
    papa = mask;
    calc (mask - (1LL << nod));
    dp[mask] = max (dp[mask], dp[mask - (1LL << nod)]);
}


int main()
{
    /// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            for (int j = 1; j <= k; j++)
            {
                now[j] = 0;
            }
        }
        else
        {
            string s;
            cin >> s;
            int x = gt (s);
            //   cout<<"="<<x<<"\n";
            now[x] = 1;
            for (int i = 1; i <= k; i++)
            {
                if (now[i])
                {
                    kek[x][i] = kek[i][x] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= 60; i++)
    {
        lg[ (1LL << i)] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (kek[i][j] == 0)
            {
                sp[i] += (1LL << (j - 1));
            }
        }
    }
    ll mask = (1LL << k) - 1LL;
    calc (mask);
    cout << dp[mask] << "\n";
    return 0;
}
/**

5 3
1
2 motarack
2 mike
1
2 light


10000
1110


10001
10101

**/