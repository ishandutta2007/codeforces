#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        cout<<(a+c>=x&&b+c>=y&&a+b+c>=x+y?"YES\n":"NO\n");
    }

    return 0;
}