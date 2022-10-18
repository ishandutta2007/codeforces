#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(y<x){
            long long u=(y/x+1)*(long long)x+y;
            cout<<u<<'\n';
        }else if(x==y)cout<<x<<'\n';
        else{
            int cof=(y-1)/x;
            cout<<(y-x*cof)/2+cof*x<<'\n';
        }
    }
    return 0;
}