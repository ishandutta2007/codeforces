#include <bits/stdc++.h>
using namespace std;

long long t,n,s,x,l=1e15,ans,a[100005],b[100005];
int main(){
//    freopen("queue.in","r",stdin);
  //  freopen("queue.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t>>s>>x;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    b[1]=a[1];
    if (a[1]<t) b[1]=t;
    for (int i=2;i<=n;++i){
        b[i]=max(a[i],b[i-1]+x);
    }
    if (b[1]>t) {
        cout<<t;
        return 0;
    }
    if (b[n]+x-1+x<s){
        cout<<s-x;
        return 0;
    }
    for (int i=1;i<=n;++i){
        if (b[i-1]+x<b[i] && b[i-1]+x+x-1<s && i>1) {
            cout<<b[i-1]+x;
            return 0;
        }
        if (a[i]!=a[i-1] && b[i]-(a[i]-1)<l && b[i]-2+x<s){
            ans=a[i]-1;
            l=b[i]-a[i]+1;
        }
    }
    cout<<ans;
}