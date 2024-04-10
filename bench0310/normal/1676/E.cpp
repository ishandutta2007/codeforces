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
        int n,q;
        cin >> n >> q;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin()+1,a.end(),greater<>());
        for(int i=1;i<=n;i++) a[i]+=a[i-1];
        while(q--)
        {
            int s;
            cin >> s;
            int p=ranges::lower_bound(a,s)-a.begin();
            if(p==n+1) p=-1;
            cout << p << "\n";
        }
    }
    return 0;
}