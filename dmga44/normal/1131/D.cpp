#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,int> psi;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 1005

string s[MAXN];
int sum[MAXN],res[MAXN][2],s2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    set<int> x;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='>')
                sum[i]+=2;
            else if(s[i][j]=='=')
                sum[i]++;
        }
        x.insert(sum[i]);
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j][i]=='<')
                s2[i]=max(sum[j]+1,s2[i]);
            else if(s[j][i]=='=')
            {
                s2[i]=sum[j];
                break;
            }
        }
        x.insert(s2[i]);
    }

    bool ok=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s2[j]<sum[i] && s[i][j]!='>')
                ok=0;
            if(s2[j]>sum[i] && s[i][j]!='<')
                ok=0;
            if(s2[j]==sum[i] && s[i][j]!='=')
                ok=0;
        }

    if(!ok)
        db("NO")
    else
    {
        map<int,int> mm;
        int cont=1;
        for(auto y : x)
        {
            mm[y]=cont;
            cont++;
        }

        db("YES")
        for(int i=0;i<n;i++)
        {
            sum[i]=mm[sum[i]];
            cout << sum[i] << ' ';
        }
        cout << '\n';
        for(int i=0;i<m;i++)
        {
            s2[i]=mm[s2[i]];
            cout << s2[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}