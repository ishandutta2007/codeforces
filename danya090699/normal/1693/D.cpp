#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    set <pair <int, int>, greater<pair<int, int>>> dp0;
    set <pair <int, int>> dp1;
    dp0.insert({0, 0});
    dp1.insert({inf, 0});

    long long an=1;
    for(int a=1; a<n; a++)
    {
        int p0 = (*dp1.lower_bound({ar[a], 0})).second;

        int p1 = (*dp0.lower_bound({ar[a], 0})).second;

        if(ar[a-1] > ar[a])
        {
            auto it = dp0.lower_bound({ar[a-1], 0});
            if((*it).second > p0)
            {
                if(it != dp0.begin())
                {
                    it--;
                    while ((*it).second >= p0) {
                        auto it2 = it;
                        if (it == dp0.begin()) {
                            dp0.erase(it2);
                            break;
                        } else {
                            it--;
                            dp0.erase(it2);
                        }
                    }
                }
                dp0.insert({ar[a - 1], p0});
            }
        }
        else
        {
            dp0.clear();
            dp0.insert({ ar[a-1], p0});
        }
        auto it0 = dp0.end();
        it0--;
        if((*it0).first != 0) dp0.insert({0, a});

        if(ar[a-1] < ar[a])
        {
            auto it = dp1.lower_bound({ar[a-1], 0});
            if((*it).second > p1)
            {
                if(it != dp1.begin())
                {
                    it--;
                    while ((*it).second >= p1) {
                        auto it2 = it;
                        if (it == dp1.begin()) {
                            dp1.erase(it2);
                            break;
                        } else {
                            it--;
                            dp1.erase(it2);
                        }
                    }
                }
                dp1.insert({ar[a-1], p1});
            }
        }
        else
        {
            dp1.clear();
            dp1.insert({ar[a-1], p1});
        }
        auto it1 = dp1.end();
        it1--;
        if((*it1).first != inf) dp1.insert({inf, a});

        an += a - min((*dp0.begin()).second, (*dp1.begin()).second) + 1;
    }
    cout<<an;
}