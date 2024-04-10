#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    stack<array<int,2>> s; //h,t
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int t=1;
        while(!s.empty()&&s.top()[0]<a[i])
        {
            t=max(t,s.top()[1]+1);
            s.pop();
        }
        if(s.empty()) t=0;
        s.push({a[i],t});
        res=max(res,t);
    }
    cout << res << "\n";
    return 0;
}