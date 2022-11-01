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
        set<int> cc;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            cc.insert(a[i]);
        }
        int idx=1;
        map<int,int> m;
        for(int x:cc) m[x]=idx++;
        for(int i=1;i<=n;i++) a[i]=m[a[i]];
        vector<set<int>> occ(n+1);
        for(int i=1;i<=n;i++) occ[a[i]].insert(i);
        vector<int> l(n+1,0);
        vector<int> r(n+1,0);
        int mx=0;
        for(int i=n;i>=1;i--)
        {
            mx=max(mx,a[i]);
            if(r[mx]==0) r[mx]=i;
            l[mx]=i;
        }
        set<int> small;
        array<int,3> res={0,0,0};
        int now=1;
        int y=0;
        for(int i=1;i<=n;i++)
        {
            y=max(y,a[i]);
            for(;now<y;now++) for(int j:occ[now]) small.insert(j);
            if(l[y]==0) continue;
            auto it=occ[y].lower_bound(i+1);
            if(it==occ[y].end()) continue;
            int two=(*it);
            if(r[y]<=two) continue;
            two=max(two,l[y]-1);
            it=small.lower_bound(i+1);
            if(it!=small.end()&&(*it)<=two) continue;
            res={i,two-i,n-two};
        }
        if(res[0]!=0) cout << "YES\n" << res[0] << " " << res[1] << " " << res[2] << "\n";
        else cout << "NO\n";
    }
    return 0;
}