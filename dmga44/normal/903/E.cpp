#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
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
#define MAXN 5005

int f[MAXN][26];
string s[MAXN];
vector<int> pos[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k,n;
    cin >> k >> n;
    bool ok=1;
    int mm=0;
    for(int i=0;i<k;i++)
    {
        cin >> s[i];
        for(int j=0;j<n;j++)
        {
            f[i][s[i][j]-'a']++;
            mm=max(f[i][s[i][j]-'a'],mm);
        }
        for(int j=0;j<26;j++)
            ok&=(f[i][j]==f[0][j]);
    }

    if(!ok)
        db(-1)
    else if(k>1)
    {
        int ma=0;
        for(int j=0;j<k;j++)
        {
            for(int i=0;i<n;i++)
                if(s[0][i]!=s[j][i])
                    pos[j].push_back(i);
            ma=max(ma,(int)pos[j].size());
        }
        if(ma>4)
            db(-1)
        else
        {
            string c=s[0];
            for(int p1=0;p1<n;p1++)
                for(int p2=p1+1;p2<n;p2++)
                {
                    swap(c[p1],c[p2]);
                    ok=1;
                    for(int i=0;i<k && ok;i++)
                    {
                        int difs=0;
                        bool pp1=0;
                        bool pp2=0;
                        for(auto y : pos[i])
                        {
                            difs+=(c[y]!=s[i][y]);
                            pp1|=(p1==y);
                            pp2|=(p2==y);
                        }
                        if(!pp1)
                            difs+=(c[p1]!=s[i][p1]);
                        if(!pp2)
                            difs+=(c[p2]!=s[i][p2]);
                        ok&=(difs==2 || (mm>1 && difs==0));
                    }
                    if(ok)
                    {
                        db(c)
                        return 0;
                    }
                    swap(c[p1],c[p2]);
                }

            db(-1)
        }
    }
    else
    {
        swap(s[0][0],s[0][1]);
        db(s[0])
    }
    return 0;
}
/**
3 4
abac
caab
acba

acab
**/