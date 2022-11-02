#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100'005;
bool arr[MAXN][2];
int main(){
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int ct=0;
    for(int i=0;i<q;++i){
        int r,c;
        cin>>r>>c;
        --r;
        if(arr[c][r]){
            if(arr[c-1][1-r])--ct;
            if(arr[c][1-r])--ct;
            if(arr[c+1][1-r])--ct;
            arr[c][r]=false;
        }
        else{
            if(arr[c-1][1-r])++ct;
            if(arr[c][1-r])++ct;
            if(arr[c+1][1-r])++ct;
            arr[c][r]=true;
        }
        cout<<((ct==0)?"Yes":"No")<<'\n';
    }
}