#include<bits/stdc++.h>

using namespace std;

int main(){
    int c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1!=c4){
        cout<<0;
        return 0;
    }
    if(c1==0&&c3>0){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}