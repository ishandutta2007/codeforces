#include<bits/stdc++.h>
using namespace std;

int n;
long long k,l1,r1,l2,r2,init,bound,ans;

void mian(){
    cin>>n>>k;
    cin>>l1>>r1;
    cin>>l2>>r2;
    if(l1>l2)swap(l1,l2),swap(r1,r2);
    init=min(r1,r2)-l2;
    bound=max(r1,r2)-min(l1,l2);
    ans=0;
    if(init>0){
        for(int i=1;i<=n;i++)k-=init;
        k=max(k,0ll);
        bound-=init;
        init=0;
    }
    for(int i=1;i<=n;i++){
        if(k>=bound){
            k-=bound;
            ans+=bound-init;
        }else{
            if(i==1){
                ans+=max(k-init,0ll);
            }else{
                ans+=min(k*2,max(k-init,0ll));
            }
            k=0;
        }
    }
    ans+=k*2;
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}