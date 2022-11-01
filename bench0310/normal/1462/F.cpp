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
        set<int> s;
        vector<int> l(n+1,0);
        vector<int> r(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> l[i] >> r[i];
            s.insert(l[i]);
            s.insert(r[i]);
        }
        map<int,int> m;
        int idx=1;
        for(int a:s) m[a]=idx++;
        for(int i=1;i<=n;i++)
        {
            l[i]=m[l[i]];
            r[i]=m[r[i]];
        }
        vector<int> one(2*n+1,0); //r
        vector<int> two(2*n+2,0); //l
        for(int i=1;i<=n;i++) one[r[i]]++;
        for(int i=1;i<=2*n;i++) one[i]+=one[i-1];
        for(int i=1;i<=n;i++) two[l[i]]++;
        for(int i=2*n;i>=1;i--) two[i]+=two[i+1];
        int res=n;
        for(int i=1;i<=n;i++) res=min(res,one[l[i]-1]+two[r[i]+1]);
        cout << res << "\n";
    }
    return 0;
}