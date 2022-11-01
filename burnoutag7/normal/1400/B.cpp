#include<bits/stdc++.h>
using namespace std;

int p,f,cs,cw,s,w;

void mian(){
    cin>>p>>f>>cs>>cw>>s>>w;
    if(w<s){
        swap(cs,cw);
        swap(s,w);
    }
    int ans=0;
    for(int i=0;i<=cs&&i*s<=p;i++){
        ans=max(ans,i+min(f/s,cs-i)+min((p-i*s)/w+(f-min(f/s,cs-i)*s)/w,cw));
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