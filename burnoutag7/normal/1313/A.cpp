#include<bits/stdc++.h>
using namespace std;

int t,r[3],a,b,c,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>r[0]>>r[1]>>r[2];
        sort(r,r+3);
        a=r[2];b=r[1];c=r[0];
        ans=0;
        if(a){a--;ans++;}
        if(b){b--;ans++;}
        if(c){c--;ans++;}
        if(a&&b){a--,b--;ans++;}
        if(a&&c){a--,c--;ans++;}
        if(b&&c){b--,c--;ans++;}
        if(a&&b&&c){a--,b--,c--;ans++;}
        cout<<ans<<'\n';
    }

    return 0;
}