#include <bits/stdc++.h>
using namespace std;

long long n,m;
map<long long,bool> used;
map<long long,long long> ans;
set<long long> nms;
map<long long,long long> qms;

long long get(long long x){
    if (used[x]) return ans[x];
    used[x]=true;
    vector<long long> v;
    v.push_back(-1);
    for (long long i=1;i<=30 && (1<<i)<=x;++i) {
        long long msk=(((1<<i)-1)&x)|(x>>i);
        long long res=get(msk);
        v.push_back(res);
    }
    sort(v.begin(),v.end());
    for (long long i=1;i<v.size();++i)
    if (v[i]>v[i-1]+1) {
        ans[x]=v[i-1]+1;
        return ans[x];
    }
    return ans[x]=v[(long long)v.size()-1]+1;
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i) {
        cin>>m;
        for (long long j=2;j<=sqrt(m);++j) if (m%j==0) {
            long long kol=0;
            while (m%j==0) {
                m/=j;
                ++kol;
            }
            nms.insert(j);
            qms[j]|=(1<<kol);
        }
        if (m>1) {
            nms.insert(m);
            qms[m] |= (2);
        }
    }
    long long res=0;
    while (!nms.empty()) {
        long long x=*nms.begin();
        nms.erase(nms.begin());
        res^=get(qms[x]);
    }
    cout<<(res ? "Mojtaba" : "Arpa");
}