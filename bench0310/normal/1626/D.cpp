#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    auto nxt=[&](int a)->int{return (1<<(32-countl_zero(uint32_t(max(0,a-1)))));};
    auto cost=[&](int a)->int{return (nxt(a)-a);};
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            a[b]++;
        }
        vector<int> v={0};
        for(int i=1;i<=n;i++) if(a[i]>0) v.push_back(a[i]);
        int m=(int)v.size()-1;
        int res=2+cost(n);
        vector<int> s(m+1,0);
        vector<int> p(19,0);
        vector<int> val(m+1,0);
        val[0]=1;
        for(int i=1;i<=m;i++)
        {
            s[i]=s[i-1]+v[i];
            val[i]=s[i]+cost(s[i]);
            res=min(res,1+cost(s[i])+cost(n-s[i]));
            for(int j=0;j<=18;j++)
            {
                while(s[i]-s[p[j]]>(1<<j)) p[j]++;
                res=min(res,val[p[j]]+(1<<j)-s[i]+cost(n-s[i]));
            }
        }
        cout << res << "\n";
    }
    return 0;
}