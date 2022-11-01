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
        vector<bool> v(2*n+1,0);
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            v[b]=1;
        }
        int one=0;
        set<int> s;
        for(int i=1;i<=2*n;i++) if(v[i]==0) s.insert(i);
        for(int i=1;i<=2*n;i++)
        {
            if(v[i]==0) continue;
            auto it=s.lower_bound(i);
            if(it==s.end()) continue;
            one++;
            s.erase(it);
        }
        s.clear();
        int two=0;
        for(int i=1;i<=2*n;i++) if(v[i]==0) s.insert(i);
        for(int i=2*n;i>=1;i--)
        {
            if(v[i]==0) continue;
            auto it=s.lower_bound(i);
            if(it==s.begin()) continue;
            two++;
            it--;
            s.erase(it);
        }
        cout << one-(n-two)+1 << "\n";
    }
    return 0;
}