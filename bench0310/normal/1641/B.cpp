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
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        map<int,int> cnt;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        bool ok=1;
        for(auto [x,y]:cnt) ok&=((y%2)==0);
        if(!ok)
        {
            cout << "-1\n";
            continue;
        }
        vector<array<int,2>> res;
        vector<int> tandem;
        int pos=1;
        auto rev=[&](int l,int r)
        {
            int tr=r;
            vector<int> b;
            for(int i=l;i<=r;i++) b.push_back(a[i]);
            int len=r-l+1;
            for(int i=l;i<=r;i++) res.push_back({pos+i-l+len-1,b[i-l]});
            tandem.push_back(2*len);
            pos+=2*len;
            l=r+1;
            r=l+len; //also taking the pair
            len++;
            ranges::reverse(b);
            b.push_back(b.back());
            for(int i=l;i<=r;i++) res.push_back({pos+i-l+len-1,b[i-l]});
            tandem.push_back(2*len);
            tandem.push_back(2);
            vector<int> nxt={0};
            for(int i=2;i<=tr;i++) nxt.push_back(a[i]);
            for(int i=tr+2;i<(int)a.size();i++) nxt.push_back(a[i]);
            a=nxt;
            pos+=(2*len+2);
        };
        while(a.size()>1)
        {
//            cout << "in with ";
//            for(int i=1;i<(int)a.size();i++) cout << a[i] << " ";
//            cout << endl;
            for(int i=2;i<(int)a.size();i++)
            {
                if(a[i]==a[1])
                {
                    rev(1,i-1);
                    break;
                }
            }
        }
        cout << res.size() << "\n";
        for(auto [x,y]:res) cout << x << " " << y << "\n";
        cout << tandem.size() << "\n";
        for(int d:tandem) cout << d << " ";
        cout << "\n";
    }
    return 0;
}