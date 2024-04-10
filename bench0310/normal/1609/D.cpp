#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin >> n >> d;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) p[i]=i;
    vector<int> sz(n+1,1);
    function<int(int)> find_set=[&](int a)->int
    {
        if(p[a]==a) return a;
        else return p[a]=find_set(p[a]);
    };
    multiset<int> s;
    for(int i=1;i<=n;i++) s.insert(1);
    auto merge_sets=[&](int a,int b)->bool
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return 0;
        s.erase(s.find(sz[a]));
        s.erase(s.find(sz[b]));
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        s.insert(sz[a]);
        return 1;
    };
    int c=0;
    for(int i=1;i<=d;i++)
    {
        int x,y;
        cin >> x >> y;
        if(merge_sets(x,y)) c++;
        vector<int> v(s.begin(),s.end());
        ranges::reverse(v);
        int len=v.size();
        int res=v[0];
        for(int j=1;j<=min(i-c,len-1);j++) res+=v[j];
        cout << res-1 << "\n";
    }
    return 0;
}