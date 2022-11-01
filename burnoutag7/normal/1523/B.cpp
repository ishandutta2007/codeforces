#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    for(int i=1,t;i<=n;i++)cin>>t;
    cout<<n*3<<'\n';
    for(int i=1;i<n;i+=2){
        cout<<"1 "<<i<<' '<<i+1<<'\n';
        cout<<"2 "<<i<<' '<<i+1<<'\n';
        cout<<"1 "<<i<<' '<<i+1<<'\n';
        cout<<"2 "<<i<<' '<<i+1<<'\n';
        cout<<"1 "<<i<<' '<<i+1<<'\n';
        cout<<"2 "<<i<<' '<<i+1<<'\n';
    }
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