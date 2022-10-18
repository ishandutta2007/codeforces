#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int c,d;
        cin>>c>>d;
        if((c+d)&1){
            cout<<"-1\n";
        }else if(c==0&&d==0)cout<<"0\n";
        else if(c==d)cout<<"1\n";
        else cout<<"2\n";
    }
    return 0;
}