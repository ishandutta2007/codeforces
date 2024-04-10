#include <bits/stdc++.h>
using namespace std;
int n,ans,k,x;
int a[1000001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i) { cin>>x; ++a[x];}
    ans=a[4]; int k=min(a[1],a[3]); ans+=k; a[1]-=k; a[3]-=k;
    k=a[1]/2; k=min(k,a[2]); ans+=k; a[1]-=(k*2); a[2]-=k;
    k=min(a[1],a[2]); ans+=k; a[1]-=k; a[2]-=k;
    //k=min(a[1],a[2]); ans+=k; a[1]-=k; a[2]-=k;
    ans+=a[1]/4; a[1]%=4;
    ans+=a[2]/2; a[2]%=2; ans+=a[3]; if (a[1]>0 || a[2]>0) ++ans;
    cout<<ans;
}