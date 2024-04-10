#include<bits/stdc++.h>
using namespace std;

int t,r,c;
char g[65][65];

bool one(){
    {
        bool f=true;
        for(int j=1;j<=c;j++){
            f&=g[1][j]=='A';
        }
        if(f)return true;
    }
    {
        bool f=true;
        for(int j=1;j<=c;j++){
            f&=g[r][j]=='A';
        }
        if(f)return true;
    }
    {
        bool f=true;
        for(int i=1;i<=r;i++){
            f&=g[i][1]=='A';
        }
        if(f)return true;
    }
    {
        bool f=true;
        for(int i=1;i<=r;i++){
            f&=g[i][c]=='A';
        }
        if(f)return true;
    }
    return false;
}

bool two(){
    if(g[1][1]=='A'||g[1][c]=='A'||g[r][1]=='A'||g[r][c]=='A')return true;
    for(int i=1;i<=r;i++){
        bool f=true;
        for(int j=1;j<=c;j++){
            f&=(g[i][j]=='A');
        }
        if(f)return true;
    }
    for(int j=1;j<=c;j++){
        bool f=true;
        for(int i=1;i<=r;i++){
            f&=(g[i][j]=='A');
        }
        if(f)return true;
    }
    return false;
}

bool three(){
    {
        bool f=false;
        for(int j=1;j<=c;j++){
            f|=g[1][j]=='A';
        }
        if(f)return true;
    }
    {
        bool f=false;
        for(int j=1;j<=c;j++){
            f|=g[r][j]=='A';
        }
        if(f)return true;
    }
    {
        bool f=false;
        for(int i=1;i<=r;i++){
            f|=g[i][1]=='A';
        }
        if(f)return true;
    }
    {
        bool f=false;
        for(int i=1;i<=r;i++){
            f|=g[i][c]=='A';
        }
        if(f)return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>r>>c;
        bool MORTAL=true,ZERO=true;
        for(int i=1;i<=r;i++){
            cin>>g[i]+1;
            for(int j=1;j<=c;j++){
                if(g[i][j]=='A'){
                    MORTAL=false;
                }else{
                    ZERO=false;
                }
            }
        }
        if(MORTAL){
            cout<<"MORTAL"<<endl;
            continue;
        }
        if(ZERO)cout<<0<<endl;
        else if(one())cout<<1<<endl;
        else if(two())cout<<2<<endl;
        else if(three())cout<<3<<endl;
        else cout<<4<<endl;
    }

    return 0;
}