#include<bits/stdc++.h>
using namespace std;

int q,n;
int x,y,mnx,mny,mxx,mxy;

void func(int a,int b,int c,int d){
    if(d==0)mny=max(mny,y);
    if(c==0)mxx=min(mxx,x);
    if(b==0)mxy=min(mxy,y);
    if(a==0)mnx=max(mnx,x);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        mnx=mny=-1e5;
        mxx=mxy=1e5;
        while(n--){
            int a,b,c,d;
            cin>>x>>y>>a>>b>>c>>d;
            func(a,b,c,d);
        }
        if(mxx<mnx||mxy<mny){
            cout<<0<<endl;
        }else{
            cout<<1<<' '<<mnx<<' '<<mny<<endl;
        }
    }

    return 0;
}