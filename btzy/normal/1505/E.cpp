#include <bits/stdc++.h>
using namespace std;
char arr[5][5];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>arr[i][j];
        }
    }
    int x=0,y=0;
    int ans=(arr[x][y]=='*');
    while(x+1<h||y+1<w){
        if(x+1<h&&arr[x+1][y]=='*'){
            ++x;
            ++ans;
        }
        else if(y+1<w){
            ++y;
            if(arr[x][y]=='*')++ans;
        }
        else if(x+1<h){
            ++x;
        }
    }
    cout<<ans<<'\n';
}