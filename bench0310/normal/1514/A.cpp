#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=10000;
    vector<bool> bad(N+1,0);
    for(int i=1;i*i<=N;i++) bad[i*i]=1;
    while(t--)
    {
        int n;
        cin >> n;
        bool res=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            res|=(bad[a]==0);
        }
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}