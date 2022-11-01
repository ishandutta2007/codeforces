#include<bits/stdc++.h>
using namespace std;

void mian(){
    int s,c=1,ans=0;
    cin>>s;
    while(s>=c){
        s-=c;
        c+=2;
        ans++;
    }
    if(s)ans++;
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