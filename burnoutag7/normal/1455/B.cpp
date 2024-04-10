#include<bits/stdc++.h>
using namespace std;

int x,ans;

void mian(){
    cin>>x;
    ans=1e9;
    for(int i=1;i<=2000;i++){
        int c=(i+1)*i/2;
        if(c==x||c>x+1)ans=min(ans,i);
        else if(c==x+1)ans=min(ans,i+1);
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