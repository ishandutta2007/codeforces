#include<bits/stdc++.h>
using namespace std;

int h,w,f[10][10];
char g[10][10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>w;
    for(int i=1;i<=h;i++)cin>>g[i]+1;
    int x=1,y=1,ans=0;
    while(x!=h||y!=w){
        ans+=g[x][y]=='*';
        bool f=true;
        for(int d=1;f&&d<=10;d++)for(int i=d;f&&i>=0;i--)if(y+i<=w&&x+d-i<=h){
            if(g[x+d-i][y+i]=='*'){
                x+=d-i;
                y+=i;
                f=false;
            }
        }
        if(f){
            if(y<w)y++;
            else x++;
        }
    }
    ans+=g[x][y]=='*';
    cout<<ans;

    return 0;
}