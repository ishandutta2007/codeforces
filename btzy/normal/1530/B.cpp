#include <bits/stdc++.h>
#define int long long
using namespace std;
char arr[20][20];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int h,w;
        cin>>h>>w;
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j)arr[i][j]='0';
        }
        for(int j=0;j<w;j+=2){
            arr[0][j]='1';
            arr[h-1][w-1-j]='1';
        }
        for(int i=2;i+2<h;i+=2){
            arr[i][0]='1';
            arr[h-1-i][w-1]='1';
        }
        for(int i=0;i<h;++i){
            for(int j=0;j<w;++j)cout<<arr[i][j];
            cout<<'\n';
        }
        cout<<'\n';
    }
}