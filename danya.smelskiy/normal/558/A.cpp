#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[100005];
int r;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    if (a[i].first>0) {
        r=i;
        break;
    }
    if (r==0) {
        cout<<a[n].second;
        return 0;
    }
    if (r==1) {
        cout<<a[1].second;
        return 0;
    }
    int ll=r-1;
    int rr=r;
    bool t=false;
    long long res1=0;
    while (true) {
        if (t==false) {
            if (ll==0) break;
            t=true;
            res1+=a[ll].second; --ll;
        } else {
            if (rr==n+1) break;
            t=false;
            res1+=a[rr].second; ++rr;
        }
    }
    long long res2=0;
    t=true;
    ll=r-1;
    rr=r;
    while (true) {
        if (t==false) {
            if (ll==0) break;
            t=true;
            res2+=a[ll].second; --ll;
        } else {
            if (rr==n+1) break;
            t=false;
            res2+=a[rr].second; ++rr;
        }
    }
    cout<<max(res1,res2);
}