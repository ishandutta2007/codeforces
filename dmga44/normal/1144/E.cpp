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

typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005

char res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    string s,t;
    cin >> s >> t;
    int b=0;
    for(int i=k;i>0;i--)
    {
        int x=s[i-1]-'a';
        int y=t[i-1]-'a';
        res[i]=(x+y+b)%26;
        if(x+y+b>=26)
            b=1;
        else
            b=0;
    }
    bool ok=1;
    if(b==1)
    {
        res[0]=1;
        ok=0;
    }

    b=0;
    for(int i=ok;i<=k;i++)
    {
        int bb=b;
        if(res[i]&1)
            b=26;
        else
            b=0;
        res[i]=(res[i]+bb)/2;
    }

    for(int i=1;i<=k;i++)
        cout << (char)(res[i]+'a');

    return 0;
}