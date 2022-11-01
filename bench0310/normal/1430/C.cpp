#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        priority_queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        vector<array<int,2>> res;
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            res.push_back({a,b});
            q.push((a+b+1)/2);
        }
        cout << q.top() << "\n";
        for(auto [a,b]:res) cout << a << " " << b << "\n";
    }
    return 0;
}