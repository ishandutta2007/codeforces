#include<bits/stdc++.h>
using namespace std;

int x,y,z;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>x>>y>>z;
    if(((x-y+z>0)&&(x-y-z<=0))||((x-y+z>=0)&&(x-y-z<0))){
        cout<<'?'<<endl;
        return 0;
    }
    if(x-y+z>0){
        cout<<'+'<<endl;
    }
    if(x-y+z<0){
        cout<<'-'<<endl;
    }
    if(x-y+z==0){
        cout<<'0'<<endl;
    }

    return 0;
}