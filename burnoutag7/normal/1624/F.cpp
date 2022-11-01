#include<bits/stdc++.h>
using namespace std;

int n,c;

bool check(int x){
    int y=1;while(n*y<x+c)y++;
    cout<<"+ "<<n*y-x-c<<endl;
    c=n*y-x;
    int z;
    cin>>z;
    return z==y;
}

int main(){

    cin>>n;
    int l=1,r=n-1,m,res;
    while(l<=r){
        m=l+r>>1;
        if(check(m)){
            res=m;
            l=m+1;
        }else r=m-1;
    }
    cout<<"! "<<res+c<<endl;

    return 0;
}