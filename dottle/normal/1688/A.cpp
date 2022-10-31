#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        if((x&(-x))==x){
            if(x==1)cout<<3<<endl;
            else cout<<x+1<<endl;
        }else cout<<(x&(-x))<<endl;
    }
}