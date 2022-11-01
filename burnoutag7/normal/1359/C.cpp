#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        ll h,c,t;
        cin>>h>>c>>t;
        ll l=0,r=h,m,res;
        while(l<=r){
            m=l+r>>1;
            if((h+c)*m+h>=t*(m<<1|1)){
                l=m+1;
                res=m<<1|1;
            }else{
                r=m-1;
            }
        }
        if(abs((h+c)*(res>>1)+h-t*res)*(res+2)>abs((h+c)*(res+2>>1)+h-t*(res+2))*res)res+=2;
        if(abs(t-(h+c>>1))*res<=abs((h+c)*(res>>1)+h-t*res))res=2;
        cout<<res<<endl;
    }

    return 0;
}