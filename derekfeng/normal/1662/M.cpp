#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m,mr=0,mw=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int r,w;
        cin>>r>>w;
        mr=max(mr,r);
        mw=max(mw,w);
    }
    if(mr+mw>n){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<string(mr,'R')<<string(n-mr,'W')<<'\n';
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