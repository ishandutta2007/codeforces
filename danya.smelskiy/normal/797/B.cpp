#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];
vector<long long> v,vv;
long long ans;
inline bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]>=0 && abs(a[i])%2==0) ans+=a[i];
        else if (abs(a[i])%2==1) {
            if (a[i]<0) v.push_back(a[i]);
            else vv.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end(),cmp);
    sort(vv.begin(),vv.end());
    if (vv.size()%2==1) {
        for (int i=0;i<vv.size();++i)
            ans+=vv[i];
        cout<<ans;
        return 0;
    }
    if (vv.size()==0) {
        ans+=v[0];
        cout<<ans;
        return 0;
    }
    if (v.size()==0) {
        for (int i=1;i<vv.size();++i)
            ans+=vv[i];
        cout<<ans;
        return 0;
    }
    long long ans1=ans;
    long long ans2=ans;
    for (int i=1;i<vv.size();++i)
            ans1+=vv[i];
    for (int i=0;i<vv.size();++i)
            ans2+=vv[i];
    ans2+=v[0];
    cout<<max(ans1,ans2);
}