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
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        bool ok=1;
        int l=1;
        while(l<=n)
        {
            int r=l;
            while(r+1<=n&&a[r+1]==a[l]) r++;
            if(l<r) rotate(p.begin()+l,p.begin()+l+1,p.begin()+r+1);
            else ok=0;
            l=r+1;
        }
        if(ok) for(int i=1;i<=n;i++) cout << p[i] << " \n"[i==n];
        else cout << "-1\n";
    }
    return 0;
}