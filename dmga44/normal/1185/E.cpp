#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 2005

string s[MAXN];
int l[26][2][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
            cin >> s[i];

        for(int i=0;i<26;i++)
        {
            l[i][0][0]=l[i][1][0]=MAXN;
            l[i][0][1]=l[i][1][1]=-1;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]!='.')
                {
                    int p=s[i][j]-'a';
                    l[p][0][0]=min(l[p][0][0],i);
                    l[p][0][1]=max(l[p][0][1],i);
                    l[p][1][0]=min(l[p][1][0],j);
                    l[p][1][1]=max(l[p][1][1],j);
                }

        bool ok=1,ant=0;
        vector<ppp> res;
        for(int i=25;i>=0;i--)
        {
            int p=i;
            if(l[p][0][0]==MAXN)
            {
                if(ant && ok)
                    res.push_back(ppp(res[0].first,res[0].first));
            }
            else
            {
                ant=1;
                if(l[p][0][0]!=l[p][0][1])
                {
                    if(l[p][1][0]!=l[p][1][1])
                        ok=0;
                    else
                    {
                        res.push_back(ppp(pii(l[p][0][0],l[p][1][0]),pii(l[p][0][1],l[p][1][0])));
                        for(int j=l[p][0][0];j<=l[p][0][1];j++)
                            ok&=(s[j][l[p][1][0]]>=(i+'a'));
                    }
                }
                else
                {
                    res.push_back(ppp(pii(l[p][0][0],l[p][1][0]),pii(l[p][0][0],l[p][1][1])));
                    for(int j=l[p][1][0];j<=l[p][1][1];j++)
                        ok&=(s[l[p][0][0]][j]>=(i+'a'));
                }
            }
        }
        if(ok)
        {
            db("YES")
            db(res.size())
            reverse(res.begin(),res.end());
            for(auto y : res)
                cout << y.first.first+1 << ' ' << y.first.second+1 << ' ' << y.second.first+1 << ' ' << y.second.second+1 << '\n';
        }
        else
            db("NO")
    }

    return 0;
}