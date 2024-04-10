#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    int x;
    cin>>x;
    //int root = static_cast<int>(ceil(sqrt(x))+0.5);
    //cout<<root<<'\n';
    /*if(x<=1) {
        cout<<x<<'\n';
        return 0;
    }
    for(int i=2;true;++i){
        int root = static_cast<int>(pow(x,1.0L/i)+0.5);
        if(root<2)break;
        if(static_cast<int>(pow(root,1.0L*i)+0.5)==x){
            cout<<root<<'\n';
            return 0;
        }
    }*/
    /*for (int i=2;i<=x;++i){
        for(int j=i*i;j<=x;j*=i){
            if(j==x){
                cout<<i<<'\n';
                return 0;
            }
        }
    }*/
    /*cout<<x<<'\n';*/
    int r=x%9;
    if(r==0)r=9;
    cout<<r<<'\n';
    /*int ans=0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    cout<<ans%10<<'\n';*/
}