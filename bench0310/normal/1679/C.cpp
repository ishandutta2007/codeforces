#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    set<int> h,v;
    for(int i=1;i<=n+1;i++)
    {
        h.insert(i);
        v.insert(i);
    }
    vector<int> ch(n+1,0);
    vector<int> cv(n+1,0);
    while(q--)
    {
        int t;
        cin >> t;
        if(t<=2)
        {
            int r,c;
            cin >> r >> c;
            if(t==1)
            {
                if((ch[r]++)==0) h.erase(r);
                if((cv[c]++)==0) v.erase(c);
            }
            else
            {
                if((--ch[r])==0) h.insert(r);
                if((--cv[c])==0) v.insert(c);
            }
        }
        else
        {
            int r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            if(*h.lower_bound(r1)>r2||*v.lower_bound(c1)>c2) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}