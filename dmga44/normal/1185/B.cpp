#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
typedef pair<char,int> pci;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        vector<pci> v1,v2;
        char c=s1[0],f=1;
        for(int j=1;j<s1.size();j++)
        {
            if(s1[j]==c)
                f++;
            else
            {
                v1.push_back(pci(c,f));
                f=1;
                c=s1[j];
            }
        }
        v1.push_back(pci(c,f));

        c=s2[0],f=1;
        for(int j=1;j<s2.size();j++)
        {
            if(s2[j]==c)
                f++;
            else
            {
                v2.push_back(pci(c,f));
                f=1;
                c=s2[j];
            }
        }
        v2.push_back(pci(c,f));

        if(v1.size()==v2.size())
        {
            bool ok=1;
            for(int j=0;j<v1.size();j++)
                ok&=(v1[j].first==v2[j].first && v1[j].second<=v2[j].second);
            if(ok)
                db("YES")
            else
                db("NO")
        }
        else
            db("NO")
    }

    return 0;
}