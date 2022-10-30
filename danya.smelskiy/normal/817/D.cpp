#include <bits/stdc++.h>
using namespace std;


int n;
pair<long long ,long long > q[1000001];
long long a[1000001];
long long mn,mx;
long long l1[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int sz=0;
    for (int i=1;i<=n;++i){
        while (sz && q[sz].first>=a[i]) --sz;
        ++sz;
        q[sz]=make_pair(a[i],i);
        l1[i]=q[sz-1].second;
    }
    sz=0;
    q[0]=make_pair(0,n+1);
    for (int i=n;i>0;--i) {
        while (sz && q[sz].first>a[i]) --sz;
        ++sz;
        q[sz]=make_pair(a[i],i);
        mn+=((i-l1[i])*(q[sz-1].second-i))*a[i];
    }
    sz=0;
    q[0]=make_pair(1e9,0);
    for (int i=1;i<=n;++i){
        while (sz && q[sz].first<=a[i]) --sz;
        ++sz;
        q[sz]=make_pair(a[i],i);
        l1[i]=q[sz-1].second;
    }
    mn*=-1;
    sz=0;
    q[0]=make_pair(1e9,n+1);
    for (int i=n;i>0;--i) {
        while (sz && q[sz].first<a[i]) --sz;
        ++sz;
        q[sz]=make_pair(a[i],i);
        mn+=(i-l1[i])*(q[sz-1].second-i)*a[i];
    }
    cout<<mn;
}