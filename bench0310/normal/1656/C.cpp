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
        vector<int> a(n);
        bool one=0;
        for(int &x:a)
        {
            cin >> x;
            one|=(x==1);
        }
        ranges::sort(a);
        bool res=(!one);
        if(one)
        {
            res=1;
            for(int i=0;i+1<n;i++) res&=(a[i]+1!=a[i+1]);
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}