#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

int main()
{
    long long n, m, i, br;
    cin >> n >> m;
    vector<long long> l(n), r(n), ans(n - 1);
    //vector< pair <long long, long long> > bridge(m);
    vector< tuple<long long, long long, long long> > event;
    set <pair<long long, long long> > ens;
    //vector< pair< pair<long long, long long> , long long>  > gate(n - 1);
    vector<long long> ends(n);
    for (i = 0; i < n ; i++)
    {
        cin >> l[i];
        cin >> r[i];
    }
    for (i = 0 ; i< m; i++)
    {
//        cin >> bridge[i].first;
//        bridge[i].second = i + 1;
        cin >> br;
        event.push_back(make_tuple(br, 0ll, i));
    }
    for(i = 0 ; i < n - 1; i++)
    {
//        gate[i].first.second = (r[i + 1] - l[i]);
//        gate[i].first.first = (l[i + 1] - r[i]);
//        gate[i].second = i;
        event.push_back(make_tuple(l[i + 1] - r[i], -1ll, i));
        event.push_back(make_tuple((r[i + 1] - l[i]), 1ll, i));
        ends[i] = (r[i + 1] - l[i]);
    }
//    sort(gate.begin(), gate.end());
//    sort(bridge.begin(), bridge.end());
//    for (auto w: gate)
//    {
//        cout << w.first.first << ' ' << w.first.second << endl;
//    }
//    for (auto z: bridge)
//        cout << z.first << endl;
    sort(event.begin(), event.end());
//    cout << event.size() << endl;
    for (i = 0; i < event.size(); i++)
    {
//        long long a, b, c;
//        tie(a, b, c) = event[i];
//        cout << a << ' ' << b << ' ' << c <<  ' ' << i << endl;
        if (get<1>(event[i]) == -1)
        {
            ens.insert(make_pair(ends[get<2>(event[i])], get<2>(event[i])));
        }
        if (get<1>(event[i]) == 0)
        {
            auto it = ens.begin();
            if (it == ens.end()) continue;
            ans[it->second] = get<2>(event[i]);
            ens.erase(it);
        }
        if (get<1>(event[i]) == 1)
        {
            auto it = ens.find(make_pair(ends[get<2>(event[i])], get<2>(event[i])));
            if (it != ens.end())
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    for (i = 0; i < n - 1; i++)
    {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}