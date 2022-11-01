#include<bits/stdc++.h>
using namespace std;

int T;
int b,p,f;
int h,c;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>b>>p>>f;
        cin>>h>>c;
        int mxb=b/2;
        int ans=0;
        if(h>=c){
            ans+=min(p,mxb)*h;
            mxb-=min(p,mxb);
            ans+=min(f,mxb)*c;
            mxb-=min(f,mxb);
        }else{
            ans+=min(f,mxb)*c;
            mxb-=min(f,mxb);
            ans+=min(p,mxb)*h;
            mxb-=min(p,mxb);
        }
        cout<<ans<<endl;
    }

    return 0;
}