#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector<pii> v;
bool isPoss(int cnt, int k)
{
    int amt = 0;
    for(int i=0;i<v.size() && amt < k && v[i].first >= cnt;++i)
    {
        amt += v[i].first/cnt;
        //cerr << "!! " << v[i].first/cnt << " added " << endl;
    }
    //cerr << endl;
    return (amt >= k);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> amt(200001, 0);
    for(int i=0;i<n;++i)
    {
        int x;
        cin >> x;
        amt[x]++;
    }
    for(int i=1;i<=200000;++i)
    {
        v.emplace_back(amt[i], i);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int l = 0;
    int r = n+1;
    int ans = 0;
    while(l<r)
    {
        int m = (l+r)/2;
        if(isPoss(m, k))
        {
            l = m+1;
        } else {
            r = m;
        }
    }
    if(isPoss(l, k)) {
        ans = l;
    } else {
        ans = l-1;
    }
    assert(isPoss(ans, k));

    vector<int> vv;
    for(int i=0;i<v.size() && vv.size() < k;++i)
    {
        for(int j=0;j<v[i].first/ans && vv.size() < k;++j)
        {
            vv.push_back(v[i].second);
        }
    }
    assert(vv.size() == k);
    for(auto& x : vv) cout << x << " ";
    cout << endl;

    return 0;
}