#include<bits/stdc++.h>
using namespace std;

int n;

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)cout<<'(';
        for(int j=0;j<i;j++)cout<<')';
        for(int j=0;j<n-i;j++)cout<<"()";
        cout<<'\n';
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