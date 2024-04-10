#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

map<pii,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int px=0,py=0;
        m[pii(px,py)]=1;
        pip res=pip(1e9,pii(0,0));
        for(int i=0;i<n;i++)
        {
            int dx=0,dy=0;
            if(s[i]=='L')
                dx=-1;
            if(s[i]=='R')
                dx=1;
            if(s[i]=='U')
                dy=1;
            if(s[i]=='D')
                dy=-1;
            px+=dx;
            py+=dy;
            if(m[pii(px,py)] && res>pip(i+1-m[pii(px,py)],pii(m[pii(px,py)],i+1)))
                res=pip(i+1-m[pii(px,py)],pii(m[pii(px,py)],i+1));
            m[pii(px,py)]=i+2;
        }

        if(res.first==1e9)
            db(-1)
        else
            cout << res.second.first << ' ' << res.second.second << '\n';
        m.clear();
    }

    return 0;
}