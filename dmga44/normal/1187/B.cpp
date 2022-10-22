#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>,
    rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

int ac[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
            ac[i+1][j]=ac[i][j];
        ac[i+1][s[i]-'a']++;
    }

    int m;
    cin >> m;
    while(m--)
    {
        string t;
        cin >> t;
        int fs[26];
        for(int i=0;i<26;i++)
            fs[i]=0;
        for(auto y : t)
            fs[y-'a']++;
        int res=0;
        for(int i=(1<<17);i;i>>=1)
        {
            if(res+i>=n)
                continue;
            bool ok=1;
            for(int j=0;j<26;j++)
                if(ac[res+i][j]<fs[j])
                    ok=0;
            if(!ok)
                res+=i;
        }
        res++;
        db(res)
    }

    return 0;
}