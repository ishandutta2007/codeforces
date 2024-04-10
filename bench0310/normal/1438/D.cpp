#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        x^=a;
    }
    vector<int> res;
    if(n&1)
    {
        for(int i=1;i+2<=n;i+=2) res.push_back(i);
        for(int i=n-4;i>=1;i-=2) res.push_back(i);
    }
    else if(x==0)
    {
        for(int i=1;i+2<=n;i+=2) res.push_back(i);
        for(int i=n-5;i>=1;i-=2) res.push_back(i);
    }
    if(!res.empty())
    {
        cout << "YES\n";
        cout << res.size() << "\n";
        for(int a:res) cout << a << " " << a+1 << " " << a+2 << "\n";
    }
    else cout << "NO\n";
    return 0;
}