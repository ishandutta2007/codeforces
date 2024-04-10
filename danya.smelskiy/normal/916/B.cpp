#include <bits/stdc++.h>
using namespace std;

long long n,k;
map<long long,long long> kol;
multiset<long long> s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    while (n) {
        long long last=0;
        for (long long j=62;j>=0;--j)
        if ((1ll<<j)<=n) {
            last=j;
            break;
        }
        n-=(1ll<<last);
        ++kol[last];
        k--;
    }
    if (k<0) {
        cout<<"No";
        return 0;
    }
    for (int i=63;i>=-63;--i)
    if (kol[i]<=k) {
        k-=kol[i];
        kol[i-1]+=kol[i]+kol[i];
        kol[i]=0;
    } else break;
    for (int i=-63;i<=63;++i)
        for (int j=1;j<=kol[i];++j)
            s.insert(i);
    while (k) {
        int x=*s.begin();
        --k;
        s.erase(s.find(x));
        s.insert(x-1);
        s.insert(x-1);
    }
    cout<<"Yes"<<'\n';
    while (!s.empty()) {
        cout<<*s.rbegin()<<" ";
        s.erase(s.find(*s.rbegin()));
    }
}