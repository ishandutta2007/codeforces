#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int l,r;
        cin>>l>>r;
        if(l<<1<=r){
            cout<<l<<' '<<(l<<1)<<endl;
        }else{
            cout<<-1<<' '<<-1<<endl;
        }
    }

    return 0;
}