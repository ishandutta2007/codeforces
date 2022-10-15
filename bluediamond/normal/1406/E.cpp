#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int) 1e5 + 7;
int n;
int lp[N];
vector<int> primes;
vector<int> small;
vector<int> big;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i <= n; j++)
        {
            lp[primes[j] * i] = primes[j];
        }
    }
    for (auto &x : primes)
    {
        if ((ll) x * x <= n)
        {
            small.push_back(x);
        }
        else
        {
            big.push_back(x);
        }
    }
    shuffle(small.begin(), small.end(), rnd);
    shuffle(big.begin(), big.end(), rnd);
    int sol = 1;
    for (auto &x : small)
    {
        if ((ll) sol * x > n)
        {
            continue;
        }
        cout << "B " << x << endl;
        int r;
        cin >> r;
        cout << "A " << x << endl;
        cin >> r;
        while (r)
        {
            sol *= x;
            if ((ll) sol * x > n)
            {
                break;
            }
            cout << "A " << sol * x << endl;
            cin >> r;
        }
    }
    if (sol > 1)
    {
        for (auto &x : big)
        {
            if ((ll) sol * x > n)
            {
                continue;
            }
            cout << "A " << x << endl;
            int r;
            cin >> r;
            if (r == 2)
            {
                sol *= x;
                break;
            }
        }
    }
    else
    {
        int rad = sqrt((int) big.size());
        while (!big.empty())
        {
            vector<int> vec;
            int l = min((int) big.size(), rad);
            for (int i = 0; i < l; i++)
            {
                vec.push_back(big.back());
                big.pop_back();
            }
            for (auto &x : vec)
            {
                cout << "B " << x << endl;
                int r;
                cin >> r;
            }
            cout << "A " << 1 << endl;
            int r;
            cin >> r;
            if (r == 1 + (int) big.size())
            {
                continue;
            }
            for (auto &x : vec)
            {
                cout << "A " << x << endl;
                int r;
                cin >> r;
                if (r)
                {
                    sol = x;
                    break;
                }
            }
            break;
        }
    }
    cout << "C " << sol << endl;
}