#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v[k];
    for(int i=0;i<k;i++) for(int j=0;j<k;j++) v[i].push_back(j);
    string euler;
    function<void(int)> go=[&](int a)
    {
        while(!v[a].empty())
        {
            int to=v[a].back();
            v[a].pop_back();
            go(to);
        }
        euler+=(a+'a');
    };
    go(0);
    reverse(euler.begin(),euler.end());
    euler.pop_back();
    for(int i=0;i<n;i++) cout << euler[i%euler.size()];
    cout << "\n";
    return 0;
}