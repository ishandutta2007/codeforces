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
#define MAXN 1000005

int ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    int n=a.size();
    for(int i=0;i<n;i++)
        ac[i+1]=(ac[i]+(a[i]=='1'));

    int sum=0;
    for(auto y : b)
        sum+=(y=='1');

    sum&=1;
    int res=0;
    for(int i=0;i<=n-b.size();i++)
        res+=!((ac[i+b.size()]-ac[i]+sum)&1);
    db(res)

    return 0;
}