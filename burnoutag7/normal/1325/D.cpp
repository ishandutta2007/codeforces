#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll u,v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>u>>v;
    if(u>v||((v-u)&1)){
        cout<<-1<<endl;
        return 0;
    }
    if(u==0&&v==0){
        cout<<0<<endl;
        return 0;
    }
    if(u==v){
        cout<<1<<endl;
        cout<<u<<endl;
        return 0;
    }
    if((u&((v-u)>>1))==0){
        cout<<2<<endl;
        cout<<(u|((v-u)>>1))<<' '<<((v-u)>>1)<<endl;
        return 0;
    }
    cout<<3<<endl;
    cout<<u<<' '<<((v-u)>>1)<<' '<<((v-u)>>1)<<endl;

    return 0;
}