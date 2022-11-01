#include<bits/stdc++.h>
using namespace std;

void mian(){
    int xa,ya,xb,yb,xf,yf;
    cin>>xa>>ya>>xb>>yb>>xf>>yf;
    if(xa==xb){
        cout<<abs(ya-yb)+2*(xf==xa&&abs(ya-yb)==abs(ya-yf)+abs(yb-yf))<<'\n';
    }else if(ya==yb){
        cout<<abs(xa-xb)+2*(yf==ya&&abs(xa-xb)==abs(xa-xf)+abs(xb-xf))<<'\n';
    }else{
        cout<<abs(ya-yb)+abs(xa-xb)<<'\n';
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