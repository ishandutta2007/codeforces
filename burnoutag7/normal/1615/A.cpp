#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,s=0,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        s+=a;
    }
    cout<<(bool)(s%n)<<'\n';
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