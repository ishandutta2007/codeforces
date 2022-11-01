#include<bits/stdc++.h>
using namespace std;

int c(int x){
    if(x==1)return 0;
    if(x==3)return 1;
    if(x==2)return 2;
    if(x==0)return 3;
    return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin>>x;
    if(x%4==0)cout<<"1 A"<<endl;
    if(x%4==1)cout<<"0 A"<<endl;
    if(x%4==2)cout<<"1 B"<<endl;
    if(x%4==3)cout<<"2 A"<<endl;

    return 0;
}