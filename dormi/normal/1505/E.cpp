#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
char arr[6][6];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }
    int x=0,y=0;
    int ans=arr[0][0]=='*';
    while(1){
        vector<pair<int,pii>> totake;
        for(int i=0;i<h;i++) {
            for (int j = 0; j < w; j++) {
                if(i>=x&&j>=y&&(i!=x||j!=y)&&arr[i][j]=='*'){
                    totake.push_back({i-x+j-y,{i,j}});
                }
            }
        }
        if(sz(totake)==0)break;
        sort(totake.begin(),totake.end());
        ans++;
        x=totake[0].second.first;
        y=totake[0].second.second;
    }
    printf("%d\n",ans);
    return 0;
}