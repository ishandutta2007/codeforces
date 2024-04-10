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
        vector<int> e(n+1,0);
        int l=2;
        while(l<=n)
        {
            if(abs(s-a[l])<abs(s))
            {
                s-=(2*a[l]);
                e[l-1]=1;
                l+=2;
            }
            else l++;
        }
        if(s==0)
        {
            vector<array<int,2>> v;
            for(int i=1;i<=n;i++)
            {
                if(e[i]==1)
                {
                    v.push_back({i,i+1});
                    i++;
                }
                else v.push_back({i,i});
            }
            cout << v.size() << "\n";
            for(auto [x,y]:v) cout << x << " " << y << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}