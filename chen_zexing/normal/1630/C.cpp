#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int a[200005],l[200005],r[200005],tar[200005];
struct node{
    int l,r;
    friend bool operator <(node a,node b){
        return a.l<b.l;
    }
};
void solve(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) l[i]=r[i]=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),r[a[i]]=i;
    for(int i=n;i>=1;i--) l[a[i]]=i;
    vector <node> v;
    for(int i=1;i<=n;i++) if(l[i]) v.push_back(node{l[i],r[i]});
    for(auto t:v) tar[t.l]=t.r;
    sort(v.begin(),v.end());
    //for(int i=1;i<=n;i++) cout<<tar[i]<<" ";puts("");
    int l=v[0].l,st=l,r=v[0].r,cnt=1;
    while(l<=n){
        int mx=0;
        for(int i=st;i<=r;i++) mx=max(mx,tar[i]);
        if(mx<=r){
            ans+=max(r-l-cnt,0);
            l=r+1,cnt=1;
            while(l<=n&&!tar[l]) l++;
            st=l,r=tar[l];
        }
        else{
            st=r+1,r=mx,cnt++;
        }
        //cout<<l<<" "<<st<<' '<<r<<" "<<ans<<endl;
    }
    printf("%d\n",ans);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}