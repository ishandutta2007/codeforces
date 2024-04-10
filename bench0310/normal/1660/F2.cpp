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
        string s;
        cin >> s;
        s="$"+s;
        ll res=0;
        map<int,int> m;
        array<int,3> c={0,0,0};
        auto f=[&](int x)->int{return ((x%3)+3)%3;};
        int x=0;
        m[0]=1;
        c[0]=1;
        for(int i=1;i<=n;i++)
        {
            int d=(s[i]=='+'?-1:1);
            if(d==1)
            {
                x++;
                c[f(x)]+=m[x];
            }
            else
            {
                c[f(x)]-=m[x];
                x--;
            }
            res+=c[f(x)];
            m[x]++;
            c[f(x)]++;
        }
        cout << res << "\n";
    }
    return 0;
}