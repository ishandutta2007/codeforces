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
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            if((r-l+1)&1) cout << "1\n";
            else if(psum(l,r)==(r-l+1)/2) cout << "0\n";
            else cout << "2\n";
        }
    }
    return 0;
}