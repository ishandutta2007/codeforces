#include<bits/stdc++.h>
using namespace std;

bool can(int a,int b,int l,int x,int r){
    if(a&&b&&!(x-l||r-x))return false;
    if(a>b){
        if(a-b>x-l)return false;
    }else{
        if(b-a>r-x)return false;
    }
    return true;
}

int a,b,c,d;
int x,y,x_1,y_1,x_2,y_2;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x_1>>y_1>>x_2>>y_2;
        if(can(a,b,x_1,x,x_2)&&can(c,d,y_1,y,y_2))cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}