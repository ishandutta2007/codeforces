#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;
        int sz=n.size();
        int lim=min(18,2*sz+1);
        int res=sz+1;
        for(ll p=1;(int)to_string(p).size()<=lim;p*=2)
        {
            string a=to_string(p);
            int x=0;
            int r=0;
            for(char c:a)
            {
                while(x<sz&&n[x]!=c) x++;
                if(x==sz) break;
                r++;
                x++;
            }
            res=min(res,sz-r+(int)a.size()-r);
        }
        cout << res << "\n";
    }
    return 0;
}