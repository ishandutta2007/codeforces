#include <bits/stdc++.h>
using namespace std;
long long n;
long long maxnot;
long long ans;
long long a[100005];
long long q[100005];
long long b[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i){
        q[i]=(abs(a[i]-a[i+1]));
        if (i%2==0) q[i]*=-1;
        ans=max(ans,abs(q[i]));
    }
    for (int i=1;i<n;++i){
        b[i]=b[i-1]+q[i];
    }
    for (int i=1;i<n;++i){
        ans=max(ans,b[i]-maxnot);
        if (i%2==0) maxnot=min(maxnot,b[i]);
    }
    maxnot=0;
    for (int i=1;i<=n;++i)
        q[i]*=-1;
    for (int i=1;i<n;++i){
        b[i]=b[i-1]+q[i];
    }
    for (int i=1;i<n;++i){
        ans=max(ans,b[i]-maxnot);
        if (i%2==1) maxnot=min(maxnot,b[i]);
    }
    cout<<ans;
}