#include <bits/stdc++.h>
using namespace std;


long long ans=0;
long long sz=2e9;
long long n,m;
long long bounty,inc,dam;
long long mx[100005];
long long st[100005];
long long regen[100005];
vector<pair<long long,pair<long long,long long> > >  qqq;
vector<pair<long long ,long long > > v[100005];
long long all;
vector<pair<long long,long long> >  qq;

void update(long long ll,long long rr) {
    if (ll>rr) return;
    qq.push_back(make_pair(ll,0));
    qq.push_back(make_pair(rr,1));
}


main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>bounty>>inc>>dam;
    for (int i=1;i<=n;++i) {
        cin>>mx[i]>>st[i]>>regen[i];
    }
    for (int i=1;i<=m;++i) {
        long long t,x,y;
        cin>>t>>x>>y;
        qqq.push_back(make_pair(t,make_pair(x,y)));
    }
    sort(qqq.begin(),qqq.end());
    for (int i=0;i<qqq.size();++i) {
        long long t=qqq[i].first;
        long long x=qqq[i].second.first;
        long long y=qqq[i].second.second;
        v[x].push_back(make_pair(t,y));
    }
    all=1;
    for (int i=1;i<=n;++i) {
        long long last=st[i];
        long long lasttime=0;
        long long x,y;
        long long l,r,t;
        for (int j=0;j<v[i].size();++j) {
            x=v[i][j].first;
            y=v[i][j].second;
            // time & health
            if (last<=dam) {
                if (regen[i]==0 || mx[i]<=dam) update(lasttime,x-1ll);
                else {
                    t=(dam-last)/regen[i];
                    l=lasttime;
                    r=min(lasttime+t,x-1);
                    if (l<=r)
                    update(l,r);
                }
            }
            lasttime=x;
            last=y;
        }
        if (last<=dam && (regen[i]==0 || mx[i]<=dam) && inc>0) {
            cout<<"-1";
            return 0;
        }
        if (last<=dam) {
            if (regen[i]==0 || mx[i]<=dam) update(lasttime,sz);
            else {
                t=(dam-last)/regen[i];
                l=lasttime;
                r=min(lasttime+t,sz);
                if (l<=r) update(l,r);
            }
        }
    }
    ans=0;
    sort(qq.begin(),qq.end());
    long long last=0;
    for (int i=0;i<qq.size();++i) {
        if (qq[i].second==0) ++last;
        else {
            ans=max(ans,last*1ll*(qq[i].first*inc+bounty));
            --last;
        }
    }
    cout<<ans;
}