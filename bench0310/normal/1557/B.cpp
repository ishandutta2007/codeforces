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
        int n,k;
        cin >> n >> k;
        vector<int> a(n,0);
        set<int> s;
        for(int &x:a)
        {
            cin >> x;
            s.insert(x);
        }
        map<int,int> h;
        int id=0;
        for(int x:s) h[x]=id++;
        for(int &x:a) x=h[x];
        int cnt=0;
        int l=0;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&a[r]+1==a[r+1]) r++;
            cnt++;
            l=r+1;
        }
        if(cnt<=k) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}