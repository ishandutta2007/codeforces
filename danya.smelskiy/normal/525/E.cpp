#include <bits/stdc++.h>
using namespace std;
long long n,k,s;
long long f[150];
map<pair<long long,long long> ,long long> used;
long long ans;
long long a[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>s;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    f[0]=1;
    int sz=1;
    while (true) {
        f[sz]=f[sz-1]*sz;
        if (f[sz]>s) break;
        ++sz;
    }
    if (n==1) {
        if (k>=1 && a[1]<=sz && f[a[1]]==s) ++ans;
        if (a[1]==s) ++ans;
        if (s==0) ++ans;
        cout<<ans;
        return 0;
    }
    int mid=(n+1)/2;
    for (int i=0;i<(1<<mid);++i) {
        int kol=0;
        vector<long long> sum;
        for (int j=0;j<mid;++j)
            if (i&(1<<j)) ++kol;
        if (kol>k) continue;
        sum.clear();
        sum.push_back(0);
        bool t=false;
        for (int j=0;j<mid;++j){
            if (i&(1<<j)) {
                if (a[j+1]>sz) {
                    t=true;
                    break;
                }
                for (int k=0;k<sum.size();++k) {
                    sum[k]+=f[a[j+1]];
                }
            } else {
                int szz=sum.size();
                for (int k=0;k<szz;++k) {
                    long long x=sum[k];
                    sum.push_back(x+a[j+1]);
                }
            }
        }
        if (t) continue;
        for (int j=0;j<sum.size();++j) {
            long long x=sum[j];
            if (x>s) continue;
            used[make_pair(kol,x)]++;
        }
    }
    int ll=n-mid;
    for (int i=0;i<(1<<ll);++i) {
        int kol=0;
        for (int j=0;j<ll;++j)
            if (i&(1<<j)) ++kol;
        if (kol>k) continue;
        vector<long long> sum;
        sum.clear();
        sum.push_back(0);
        bool t=false;
        for (int j=0;j<ll;++j){
            if (i&(1<<j)) {
                if (a[j+mid+1]>sz) {
                    t=true;
                    break;
                }
                for (int k=0;k<sum.size();++k) {
                    sum[k]+=f[a[j+mid+1]];
                }
            } else {
                int szz=sum.size();
                for (int k=0;k<szz;++k) {
                    long long x=sum[k];
                    sum.push_back(x+a[j+mid+1]);
                }
            }
        }
        if (t) continue;

        for (int j=0;j<sum.size();++j) {
            long long x=sum[j];
            if (x>s) continue;
            if (x==0 && i!=0) continue;
            for (int r=kol;r<=k;++r)
                ans+=used[make_pair(k-r,s-x)];
        }
    }
    cout<<ans;

}