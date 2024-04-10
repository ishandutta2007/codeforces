#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    s="$"+s;
    vector c(3,vector(n+1,array<int,4>{0,0,0,0}));
    for(int o=0;o<3;o++)
    {
        for(int i=1;i<=n;i++)
        {
            c[o][i]=c[o][i-1];
            if((i%3)==o)
            {
                c[o][i][s[i]-'a']++;
                c[o][i][3]++;
            }
        }
    }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        if(l==r) cout << "0\n";
        else if(l+1==r) cout << (s[l]==s[r]) << "\n";
        else
        {
            int res=n;
            string t="abc";
            do
            {
                int now=0;
                for(int i=0;i<3;i++)
                {
                    int o=(l+i)%3;
                    now+=(c[o][r][3]-c[o][l-1][3]-(c[o][r][t[i]-'a']-c[o][l-1][t[i]-'a']));
                }
                res=min(res,now);
            }while(next_permutation(t.begin(),t.end()));
            cout << res << "\n";
        }
    }
    return 0;
}