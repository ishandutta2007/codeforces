#include <bits/stdc++.h>
using namespace std;
long long h,n,x,y,z;
vector<pair<long long,long long> > yes[100],no[100],qq,qq1;

long long q;
inline void nooo(){
    cout<<"Game cheated!";
    exit(0);
}
inline void chek(long long l,long long r,long long ll,long long rr){
        if (l>r) return;
        if (l>rr || r<ll) return;
        ll=max(ll,l);
        rr=min(rr,r);
        qq1.push_back(make_pair(ll,rr));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>h>>n;
    for (int i=1;i<=n;++i) {
        cin>>x>>y>>z;
        cin>>q;
        if (q==0) no[x].push_back(make_pair(y,z));
        else yes[x].push_back(make_pair(y,z));
    }
    yes[1].push_back(make_pair(1,1));
    long long lk,rk;
    for (int i=1;i<=h;++i) {
        long long l=yes[i][0].first;
        long long r=yes[i][0].second;
        for (int j=0;j<yes[i].size();++j) {
            long long ll=yes[i][j].first;
            long long rr=yes[i][j].second;
            if (ll>r || rr<l) nooo();
            l=max(ll,l);
            r=min(r,rr);
        }
        if (i==h) lk=l,rk=r;
        else
        yes[i+1].push_back(make_pair(l*2,r*2+1));
        if (no[i].size()) {
            for (int j=0;j<no[i].size();++j) {
                no[i+1].push_back(make_pair(no[i][j].first*2,no[i][j].second*2+1));
            }
        }
    }
    long long l=lk;
    long long r=rk;
    if (l>r) {
        cout<<"Data not sufficient!";
        return 0;
    }
    for (int i=0;i<no[h].size();++i) {
        qq.push_back(make_pair(no[h][i].first,0));
        qq.push_back(make_pair(no[h][i].second,1));
    }
    qq.push_back(make_pair(0,0));
    qq.push_back(make_pair(0,1));
    qq.push_back(make_pair((long long)1<<h,0));
    qq.push_back(make_pair((long long)1<<h,1));
    sort(qq.begin(),qq.end());
    int last=0;
    for (int i=0;i<qq.size();++i) {
        if (qq[i].second==0) {
            if (last==0 && i) {
                chek(qq[i-1].first+1,qq[i].first-1,l,r);
            }
            last++;
        } else {
            --last;
        }
    }
    if (qq1.size()==0) nooo();
    for (int i=0;i<qq1.size();++i) {
        long long ll=qq1[i].first;
        long long rr=qq1[i].second;
        if (ll>r || rr<l) {
            cout<<"Data not sufficient!";
            return 0;
        }
        l=max(l,ll);
        r=min(r,rr);
    }
    if (l<r) cout<<"Data not sufficient!";
    else cout<<l;
}