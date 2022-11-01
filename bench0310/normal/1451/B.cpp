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
        string s;
        cin >> s;
        s="$"+s;
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            int sz=r-l+1;
            string a="$"+s.substr(l,sz);
            vector<int> one(n+1,0);
            vector<int> two(n+2,0);
            for(int i=1;i<=n;i++)
            {
                one[i]=one[i-1];
                if(one[i]+1<=sz&&s[i]==a[one[i]+1]) one[i]++;
            }
            for(int i=n;i>=1;i--)
            {
                two[i]=two[i+1];
                if(two[i]<sz&&s[i]==a[sz-two[i]]) two[i]++;
            }
            bool ok=0;
            for(int i=1;i<=n;i++) ok|=(one[i-1]>0&&two[i+1]>0&&one[i-1]+two[i+1]>=sz);
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}