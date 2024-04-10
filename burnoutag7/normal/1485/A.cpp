#include<bits/stdc++.h>
using namespace std;

int a,b,c,cc,ans,cnt;

void mian(){
    ans=1e9;
    cnt=0;
    cin>>a>>b;
    if(b==1){
        cnt++;
        b=2;
    }
    while(cnt<ans){
        c=a;
        cc=0;
        while(c){
            c/=b;
            cc++;
        }
        ans=min(ans,cc+cnt);
        cnt++;
        b++;
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