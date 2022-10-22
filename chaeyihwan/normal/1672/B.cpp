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

void solve()
{
    string s; cin >> s;
    int n = s.size();
    
    int now = 0;
    bool flag = true;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'A') now++;
        else now--;
        
        if(now < 0) flag = false;
    }
    
    if(s[n-1] == 'A') flag = false;
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}