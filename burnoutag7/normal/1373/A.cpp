#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,b,c;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        if(c>a)cout<<1<<' ';
        else cout<<"-1 ";
        if(c<a*b)cout<<b;
        else cout<<"-1";
        cout<<endl;
    }

    return 0;
}