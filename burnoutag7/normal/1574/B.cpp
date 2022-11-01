#include<bits/stdc++.h>
using namespace std;

void mian(){
    int a[3],m;
    cin>>a[0]>>a[1]>>a[2]>>m;
    sort(a,a+3);
    int mn=max(0,a[2]-a[1]-a[0]-1),mx=a[0]+a[1]+a[2]-3;
    cout<<(mn<=m&&mx>=m?"YES\n":"NO\n");
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