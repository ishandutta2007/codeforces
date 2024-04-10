#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m;
int main(){
    int T;
    cin>>T;
    while(T--){
        int S=-1,id=1;
        cin>>n;
        for(i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x>S)S=x,id=i;
        }cout<<id<<endl;
    }
}