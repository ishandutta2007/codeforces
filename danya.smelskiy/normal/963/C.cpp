#include <bits/stdc++.h>
using namespace std;



int n;
pair<long long,long long> a[200005];
map<long long,int> num;
vector<pair<long long,long long> > v[200005];
long long q;
long long b[200005];
int all;

int main() {
//    freopen("schedule.in","r",stdin);
  //  freopen("schedule.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second>>b[i];
        if (!num.count(a[i].first)) num[a[i].first]=++all;
        v[num[a[i].first]].push_back(make_pair(a[i].second,b[i]));
    }
    vector<pair<long long,long long> > last;
    for (int i=1;i<=all;++i) {
        vector<pair<long long,long long> > vv;
        long long tt=0;
        for (int j=0;j<v[i].size();++j) {
            tt=__gcd(tt,v[i][j].second);
        }
        for (int j=0;j<v[i].size();++j) {
            v[i][j].second/=tt;
            vv.push_back(v[i][j]);
        }
        sort(vv.begin(),vv.end());
        for (int j=1;j<vv.size();++j)
        if (vv[j]==vv[j-1]) {
            assert(false);
        }
        if (i>1 && last!=vv) {
            cout<<"0";
            return 0;
        }
        last=vv;
        q=__gcd(q,tt);
    }
    long long ans=0;
    for (long long i=1;i*i<=q;++i)
    if (q%i==0) {
        ++ans;
        if(q/i!=i) ++ans;
    }
    cout<<ans;
}