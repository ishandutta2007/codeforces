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
        int a,b,k;
        cin >> a >> b >> k;
        vector<array<int,2>> v(k);
        vector<int> ca(a+1,0);
        vector<int> cb(b+1,0);
        for(int i=0;i<k;i++) cin >> v[i][0];
        for(int i=0;i<k;i++) cin >> v[i][1];
        for(int i=0;i<k;i++)
        {
            ca[v[i][0]]++;
            cb[v[i][1]]++;
        }
        ll res=0;
        for(int i=0;i<k;i++)
        {
            auto [x,y]=v[i];
            res+=(k-ca[x]-cb[y]+1);
        }
        cout << res/2 << "\n";
    }
    return 0;
}