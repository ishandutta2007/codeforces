#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    int last = 0;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        
        if (x > last) {
            last = x;
        } else {
            ans += (last + 1 - x);
            ++last;
        }
    }
    cout << ans << endl;
    
    
    return 0;
}