#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int fs[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
            fs[i+1][j]=fs[i][j];
        fs[i+1][s[i]-'a']++;
    }

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l>> r;
        l--,r--;
        int cont=0;
        for(int i=0;i<26;i++)
            if(fs[r+1][i]-fs[l][i])
                cont++;
        if(cont>1)
        {
            if(s[l]!=s[r] || cont>2)
                db("Yes")
            else
            {
//                vector<int> vs;
//                for(int i=0;i<26;i++)
//                    if(fs[r+1][i]-fs[l][i])
//                        vs.push_back(fs[r+1][i]-fs[l][i]);
//
//                sort(vs.rbegin(),vs.rend());
//
//                if(vs[1]>1)
//                    db("Yes")
//                else
                db("No")
            }
        }
        else
        {
            if(l!=r)
                db("No")
            else
                db("Yes")
        }
    }

    return 0;
}