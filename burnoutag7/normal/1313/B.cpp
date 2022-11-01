#include<bits/stdc++.h>
using namespace std;

int calcmin(int n,int x,int y){
    int xp=x-1,yp=y-1;
    int f=min(n,max(1,x+y-n+1));
    return f;
}

int calcmax(int n,int x,int y){
    int xp=x-1,yp=y-1;
    int ax=min(xp,n-y),ay=min(yp,n-x);
    xp-=ax;
    yp-=ay;
    assert(xp==yp);
    return ax+ay+xp+1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T,n,x,y;
    cin>>T;
    while(T--){
        cin>>n>>x>>y;
        cout<<calcmin(n,x,y)<<' '<<calcmax(n,x,y)<<'\n';
    }

    return 0;
}