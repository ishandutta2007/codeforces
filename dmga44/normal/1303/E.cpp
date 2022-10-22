#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 405

int last[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tt;
    cin >> tt;
    while(tt--)
    {
        string s,t;
        cin >> s >> t;
        int n=s.size();
        int m=t.size();
        bool ok=0;
        for(int i=0;i<m;i++)
        {
            int s1=i+1;
            int s2=m-s1;
            for(int j=0;j<=s1;j++)
                last[j]=-1;
            last[0]=0;

            for(int j=0;j<n;j++)
                for(int k=s1;k>=0;k--)
                {
                    if(last[k]==-1)
                        continue;
                    if(k!=s1 && s[j]==t[k])
                        last[k+1]=max(last[k+1],last[k]);
                    if(last[k]!=s2 && s[j]==t[s1+last[k]])
                        last[k]++;
                }
            ok|=(last[s1]==s2);
        }
        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}
/**
5
a
aa
ababcd
abcba
a
b
defi
fed
xyz
x
**/