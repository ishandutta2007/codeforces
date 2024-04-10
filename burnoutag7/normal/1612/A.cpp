#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        if(x+y&1)cout<<"-1 -1\n";
        else cout<<x/2<<' '<<(y+1)/2<<'\n';
    }

    return 0;
}