#include <bits/stdc++.h>
using namespace std;


int n,q;
int a[2000005];
long long s[2000005];
long long b;
int to[2000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[n+i]=a[i];
    }
    for (int i=1;i<=n+n;++i)
        s[i]=(s[i-1]+a[i]);
    for (int i=1;i<=q;++i) {
        cin>>b;
        int r=n+n;
        int pos=1;
        int mn=1e9;
        for (int j=n+n;j>0;--j) {
            while (s[r]-s[j-1]>b) --r;
            to[j]=r;
        }
        for (int j=1;j<=n;++j)
        if (to[j]-j<mn) {
            mn=to[j]-j;
            pos=j;
        }
        int ans=n;
        for (int j=pos;j<=to[pos]+1;++j) {
            int res=0;
            int last=j;
            int kol=0;
            while (kol<n) {
                ++res;
                kol+=to[last]-last+1;
                last=to[last]+1;
                if (last>n) last-=n;
            }
            ans=min(ans,res);
        }
        cout<<ans<<'\n';
    }
}