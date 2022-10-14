#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int xc[8]={1,-1,0,0,1,-1,1,-1},yc[8]={0,0,1,-1,1,-1,-1,1};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int h,w;
        cin>>h>>w;
        vector<vector<char>> ans(h,vector<char>(w,'0'));
        auto good=[&](int x, int y){
            if(ans[x][y]=='1')return false;
            for(int j=0;j<8;j++){
                int nx=x+xc[j],ny=y+yc[j];
                if(nx>=0&&nx<h&&ny>=0&&ny<w){
                    if(ans[nx][ny]=='1')return false;
                }
            }
            return true;
        };
        for(int i=0;i<w;i++){
            if(good(0,i))ans[0][i]='1';
        }
        for(int i=0;i<h;i++){
            if(good(i,w-1))ans[i][w-1]='1';
        }
        for(int i=w-1;i>=0;i--){
            if(good(h-1,i))ans[h-1][i]='1';
        }
        for(int i=h-1;i>=0;i--){
            if(good(i,0))ans[i][0]='1';
        }
        for(auto x:ans){
            for(auto y:x)printf("%c",y);
            printf("\n");
        }
    }
    return 0;
}