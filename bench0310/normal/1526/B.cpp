#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1099;
    vector<int> v={11,111};
    vector<bool> a(N+1,0);
    a[0]=1;
    for(int i=1;i<=N;i++)
    {
        for(int t:v) if(t<=i&&a[i-t]) a[i]=1;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        bool res=1;
        if(x<=N) res=a[x];
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}