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
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+((s[i]=='+')^(i&1));
        auto psum=[&](int l,int r)->int{return (sum[r]-sum[l-1]);};
        vector<array<int,2>> v;
        for(int i=1;i<=n;i++) v.push_back({sum[i-1]+sum[i]-i,i});
        sort(v.begin(),v.end());
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            vector<int> res;
            if(((r-l+1)%2)==0)
            {
                if(psum(l,r)==(r-l+1)/2)
                {
                    cout << "0\n";
                    continue;
                }
                res.push_back(r--);
            }
            int x=sum[r]+sum[l-1]-l-(r-l)/2;
            res.push_back((*lower_bound(v.begin(),v.end(),array<int,2>{x,l}))[1]);
            cout << res.size() << "\n";
            for(int y:res) cout << y << " ";
            cout << "\n";
        }
    }
    return 0;
}