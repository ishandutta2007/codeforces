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
        vector<int> res;
        auto solve=[&](int a,int b,int A,int B)
        {
            for(int x=0;x<=a;x++)
            {
                if(x<=A&&0<=a-x&&a-x<=B) res.push_back(A-x+a-x);
            }
        };
        int a,b;
        cin >> a >> b;
        int n=a+b;
        solve(a,b,n/2,n-n/2);
        solve(a,b,n-n/2,n/2);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        cout << res.size() << "\n";
        for(int k:res) cout << k << " ";
        cout << "\n";
    }
    return 0;
}