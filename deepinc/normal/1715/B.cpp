#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    int t; cin>>t; while(t--){
        int n,k,b; long long s; cin>>n>>k>>b>>s;
        if(1ll*b*k+(k-1ll)*n<s || 1ll*b*k>s)puts("-1");
        else{
            s-=1ll*b*k;
            for(int i=1;i<=n;++i) printf("%lld ",(i==1?1ll*b*k:0ll)+min(k-1ll,s)), s-=min(k-1ll,s);
            puts("");
        }
    }
}