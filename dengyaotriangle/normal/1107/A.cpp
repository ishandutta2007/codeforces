#include<bits/stdc++.h>

using namespace std;

const int maxn=506;

char x[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>x;
        if(n>2){
            cout<<"YES\n2\n";
            cout<<x[0]<<' '<<(x+1)<<'\n';
        }else{
            if(x[0]<x[1]){
                cout<<"YES\n2\n"<<x[0]<<' '<<x[1]<<'\n';
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}