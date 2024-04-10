#include<bits/stdc++.h>
using namespace std;

int len(int x){
    int r=0;
    while(x){
        r++;
        x/=10;
    }
    return r;
}

int x,y,g,a,b,c;

void mian(){
    cin>>a>>b>>c;
    g=1;
    while(len(g)<c)g*=2;
    x=y=g;
    while(len(x)<a)x*=3;
    while(len(y)<b)y*=5;
    cout<<x<<' '<<y<<'\n';
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