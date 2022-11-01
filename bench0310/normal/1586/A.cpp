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
        vector<int> a(n+1,0);
        int s=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        int d=0;
        for(int i=2;i*i<=s;i++) if((s%i)==0) d=i;
        int r=0;
        if(d==0)
        {
            for(int i=1;i<=n;i++) if(a[i]&1) r=i;
        }
        vector<int> res;
        for(int i=1;i<=n;i++) if(i!=r) res.push_back(i);
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}