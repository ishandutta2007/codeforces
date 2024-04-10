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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    if(k>4*n*m-2*n-2*m)
        db("NO")
    else
    {
        db("YES")
        vector<pls> tot;
        if(m>1)
            tot.push_back(pls(m-1,"R"));

        if(m>1)
            tot.push_back(pls(m-1,"L"));

        for(int i=0;i<n-1;i++)
        {
            tot.push_back(pls(1,"D"));
            if(m>1)
            {
                tot.push_back(pls(m-1,"RUD"));
                tot.push_back(pls(m-1,"L"));
            }
        }
        if(n>1)
            tot.push_back(pls(n-1,"U"));

        vector<pls> ans;
        for(int i=0;i<tot.size();i++)
        {
            if(tot[i].first*tot[i].second.size()<=k)
            {
                k-=tot[i].first*tot[i].second.size();
                ans.push_back(tot[i]);
            }
            else
            {
                int p1=k/tot[i].second.size();
                if(p1)
                    ans.push_back(pls(p1,tot[i].second));
                string last="";
                for(int j=0;j<k%tot[i].second.size();j++)
                    last=last+tot[i].second[j];
                if(k%tot[i].second.size())
                    ans.push_back(pls(1,last));
                break;
            }
        }

        db(ans.size())
        for(auto y : ans)
            cout << y.first << ' ' << y.second << '\n';
//        for(auto y : tot)
//            cout << y.first << ' ' << y.second << '\n';
    }

    return 0;
}