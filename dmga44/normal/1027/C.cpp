#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 10005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        set<int> xs;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            a[x]++;
            xs.insert(x);
        }

        vector<int> pos;
        for(auto i : xs)
        {
            if(a[i]>1)
                pos.push_back(i);
            if(a[i]>3)
                pos.push_back(i);
        }

        pii res=pii(0,0);
        for(int i=0;i<pos.size()-1;i++)
            if(res.first==0 || (res.first*pos[i+1]<res.second*pos[i]))
                res=pii(pos[i],pos[i+1]);
        for(auto y : xs)
            a[y]=0;
        cout << res.first << ' ' << res.first << ' ' << res.second << ' ' << res.second << '\n';
    }

    return 0;
}