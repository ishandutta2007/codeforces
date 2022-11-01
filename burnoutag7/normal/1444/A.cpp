#include<bits/stdc++.h>
using namespace std;

long long p,c,ans,d;
int q;

void mian(){
    cin>>p>>q;
    ans=0;
    for(int i=2;i*i<=q;i++){
        if(q%i==0){
            d=1;
            while(q%i==0)q/=i,d*=i;
            c=p;
            while(c%d==0)c/=i;
            ans=max(ans,c);
        }
    }
    if(q>1){
        c=p;
        while(c%q==0)c/=q;
        ans=max(ans,c);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}