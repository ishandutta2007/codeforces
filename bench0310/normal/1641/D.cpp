#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<array<int,5>,int>> h;
    vector<pair<int,array<int,32>>> w(n);
    vector<int> pos(n,0);
    vector<int> add;
    int tcnt=-1;
    for(int i=0;i<n;i++)
    {
        array<int,5> a; a.fill(0);
        for(int j=0;j<m;j++) cin >> a[j];
        sort(a.begin(),a.begin()+m);
        cin >> w[i].first;
        for(int mask=0;mask<(1<<m);mask++)
        {
            array<int,5> b; b.fill(0);
            int c=0;
            for(int j=0;j<m;j++) if(mask&(1<<j)) b[c++]=a[j];
            h.push_back({b,i});
        }
    }
    ranges::sort(h);
    int sz=h.size();
    for(int i=0;i<sz;i++)
    {
        if(i==0||h[i].first!=h[i-1].first)
        {
            tcnt++;
            int c=0;
            for(int j=0;j<m;j++) c+=(h[i].first[j]!=0);
            add.push_back((c&1)?-1:1);
        }
        int id=h[i].second;
        w[id].second[pos[id]++]=tcnt;
    }
    ranges::sort(w,[&](const auto &a,const auto &b){return (a.first<b.first);});
    const int inf=2000000001;
    int l=1,r=inf;
    vector<int> cnt(tcnt+1,0);
    while(l<r-1)
    {
        int lim=midpoint(l,r);
        ll now=0;
        int p=-1;
        for(int i=n-1;i>=0;i--)
        {
            while(p+1<n&&w[p+1].first+w[i].first<=lim)
            {
                p++;
                for(int j=0;j<(1<<m);j++) cnt[w[p].second[j]]++;
            }
            for(int j=0;j<(1<<m);j++) now+=(add[w[i].second[j]]*cnt[w[i].second[j]]);
        }
        for(;p>=0;p--) for(int j=0;j<(1<<m);j++) cnt[w[p].second[j]]--;
        if(now/2>0) r=lim;
        else l=lim;
    }
    if(r<inf) cout << r << "\n";
    else cout << "-1\n";
    return 0;
}