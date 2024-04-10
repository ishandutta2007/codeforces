#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T,x1,y1,z1,x2,y2,z2;
    cin>>T;
    while(T--){
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        int ans=0,tmp;
        tmp=min(z1,y2);
        z1-=tmp;
        y2-=tmp;
        ans+=tmp*2;
        tmp=min(z1,z2);
        z1-=tmp;
        z2-=tmp;
        tmp=min(x1,z2);
        x1-=tmp;
        z2-=tmp;
        tmp=min(y1,z2);
        ans-=tmp*2;
        cout<<ans<<'\n';
    }

    return 0;
}