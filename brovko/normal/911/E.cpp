#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, used[200005], used2[200005];
vector <int> v, u;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<k; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            used[x] = 1;
        }

    for(int i=1; i<=n; i++)
        if(used[i] == 0)
            u.push_back(i);

    int m = u.size();
    for(int i=0; i<m; i++)
    {
        if(i == m-1 || u[i+1] - u[i] > 1)
        {
            int j = i;
            while(j >= 0 && u[j] != -1)
            {
                v.push_back(u[j]);
                u[j] = -1;
                j--;
            }
        }
    }

    int Min = 1;
    stack <int> s;

    for(auto to:v)
    {
        s.push(to);
        while(!s.empty() && s.top() == Min)
        {
            s.pop();
            Min++;
        }
    }

    if(Min <= n)
    {
        cout << -1;
        return 0;
    }

    for(auto to:v)
        cout << to << ' ';
}