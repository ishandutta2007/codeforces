// okiuds

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define pb push_back
#define se second
#define goddess ios_base::sync_with_stdio(0), cin.tie(0);
#define mod 1000000007

using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, sts[1002], block[1002], szrem, centru;
vector<int> v[1002];

void dfs(int dad, int nod)
{
    sts[nod] = 1;
    bool ok = 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad || block[vecin])
            continue;
        dfs(nod, vecin);
        sts[nod] += sts[vecin];
        if(sts[vecin] > szrem / 2)
            ok = 0;
    }
    if(szrem - sts[nod] > szrem / 2)
        ok = 0;
    if(ok)
        centru = nod;
}
bool seen[1002];
int ac(int nod)
{
    memset(seen, 0, sizeof(seen));
    deque<int> d;
    d.pb(nod);
    seen[nod] = 1;
    int ans = 0;
    while(!d.empty())
    {
        int nod = d[0];
        d.pop_front();
        ++ans;
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(seen[vecin] || block[vecin])
                continue;
            d.pb(vecin);
            seen[vecin] = 1;
        }
    }
    return ans;
}
int main()
{
    goddess

    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    centru = 1;
    szrem = n;
    int questions = 0;
    while(szrem > 1)
    {
        dfs(0, centru);
        vector<int> pos;
        pos.pb(centru);
        for(int i = 0; i < v[centru].size(); ++i)
        {
            int vecin = v[centru][i];
            if(block[vecin])
                continue;
            pos.pb(vecin);
        }
        shuffle(pos.begin() + 1, pos.end(), rng);
        block[centru] = 1;
        vector<int> pa;
        if(pos.size() == 1)
        {
            cout << "! " << centru << endl;
            return 0;
        }
        else
            if(pos.size() == 2)
            {
                int ans;
                ++questions;
                cout << "? " << pos[0] << " " << pos[1] << endl;
                cin >> ans;
                if(questions > n/2)
                {
                    while(1);
                }
                if(ans == centru)
                {
                    cout << "! " << centru << endl;
                    return 0;
                }
                centru = ans;
            }
            else
            {
                bool always = 1;
                for(int i = 1; i < pos.size(); i += 2)
                    if(i + 1 < pos.size())
                    {
                        int ans;
                        ++questions;
                        cout << "? " << pos[i] << " " << pos[i+1] << endl;
                        cin >> ans;
                        if(ans != centru)
                            always = 0;
                        if(questions > n/2)
                        {
                            while(1);
                        }
                        if(ans != centru)
                        {
                            block[centru] = 1;
                            centru = ans;
                            break;
                        }
                    }
                    else
                    {
                        int ans;
                        ++questions;
                        cout << "? " << pos[i] << " " << pos[i-1] << endl;
                        cin >> ans;
                        if(questions > n/2)
                        {
                            while(1);
                        }
                        if(ans != centru)
                            always = 0;
                        if(ans != centru)
                        {
                            block[centru] = 1;
                            centru = ans;
                            break;
                        }
                    }
                if(always)
                {
                    cout << "! " << centru << endl;
                    return 0;
                }
            }
        szrem = ac(centru);
    }
    cout << "! " << centru << endl;
    return 0;
}