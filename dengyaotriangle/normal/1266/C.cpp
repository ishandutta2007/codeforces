#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int r,c;

int main(){
    ios::sync_with_stdio(0);
    cin>>r>>c;
    if(r==1&&c==1){cout<<0;return 0;}
    if(r<=c){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout<<i*(j+r)<<' ';
            }
            cout<<endl;
        }
    }else{
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout<<j*(i+c)<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}