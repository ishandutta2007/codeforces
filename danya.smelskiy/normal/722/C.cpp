#include <bits/stdc++.h>
using namespace std;
long long n,x;
long long a[100001];
set<long long> s;
multiset<pair<long long,pair<long long ,long long> > > ss;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    a[n+1]=a[n];
    s.insert(0); s.insert(n+1);
    ss.insert(make_pair(a[n],make_pair(0,n+1)));
    long long ans=0;
    for (int i=1;i<=n;++i){
        cin>>x;
        set<long long >::iterator q = s.lower_bound(x);
        set<long long >::iterator q2= s.upper_bound(x);
        --q;
        long long qq=*q;
        long long qq2=*q2;
        long long z=a[qq2-1]-a[qq];
         ss.erase(make_pair(z,make_pair(qq,qq2)));
        ss.insert(make_pair(a[x-1]-a[qq],make_pair(qq,x)));
        ss.insert(make_pair(a[qq2-1]-a[x],make_pair(x,qq2)));
        ans=ss.rbegin()->first;
        cout<<ans<<endl;;
        s.insert(x);
    }
}