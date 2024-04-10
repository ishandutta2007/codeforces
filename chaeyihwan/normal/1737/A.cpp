#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int cnt[26];

void solve()
{
    int n, k; cin >> n >> k;
    int c = n/k;
    
    for(int i=0;i<26;i++) cnt[i] = 0;
    string s; cin >> s;
    for(int i=0;i<n;i++) cnt[s[i]-'a']++;
    
    for(int i=1;i<26;i++) cnt[i] = min(cnt[i], cnt[i-1]);
    int now = min(25, c-1);
    for(int i=1;i<=k;i++)
    {
        while(now >= 0 && cnt[now] < i) now--;
        cout << (char)('a' + now + 1);
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}