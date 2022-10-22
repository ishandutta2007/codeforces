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
#define MAXN 100005

bool hay[MAXN][26];
string s[MAXN];

ll solve(int p,int x)
{
    bool ok=(s[p][0]-'a'==x);
    int n=s[p].size();
    for(int i=1;i<n;i++)
        ok&=(s[p][i]==s[p][i-1]);
    if(ok && hay[p][x])
        return n+((n+1)*(solve(p-1,x)));
    int res=0;
    for(int i=0;i<26;i++)
    {
        string xxx;
        if(p)
        {
            if(!hay[p][i])
                continue;
            string add=" ";
            add[0]='a'+i;
            xxx=s[p]+add+s[p];
        }
        else
            xxx=s[p];
        int act=0,ant=-1;
        for(int j=0;j<xxx.size();j++)
        {
            if(xxx[j]-'a'!=ant)
            {
                if(ant==x)
                    res=max(res,act);
                ant=xxx[j]-'a';
                act=1;
            }
            else
                act++;
        }
        if(ant==x)
            res=max(res,act);
    }
    return max(res,1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<26;j++)
            hay[i+1][j]=hay[i][j];
        int m=s[i].size();
        for(int j=0;j<m;j++)
            hay[i+1][s[i][j]-'a']=1;
    }

    bool ok=1;
    for(int i=0;i+1<s[n-1].size();i++)
        ok&=(s[n-1][i]==s[n-1][i+1]);
    if(ok && hay[n-1][s[n-1][0]-'a'])
        db(s[n-1].size()+((s[n-1].size()+1)*(solve(n-2,s[n-1][0]-'a'))))
    else
    {
        int res=0;
        for(int i=0;i<26;i++)
        {
            if(!hay[n-1][i])
                continue;
            string add=" ";
            add[0]='a'+i;
            string xxx=s[n-1]+add+s[n-1];
            int act=0,ant=-1;
            for(int j=0;j<xxx.size();j++)
            {
                if(xxx[j]!=ant)
                {
                    res=max(res,act);
                    ant=xxx[j];
                    act=1;
                }
                else
                    act++;
            }
        }
        db(res)
    }

    return 0;
}
/**
3
bb
ba
aaa
**/