#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,c=0,t;
    cin>>n;
    while(n--){
        cin>>t;
        c+=t!=2;
    }
    cout<<c<<'\n';
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