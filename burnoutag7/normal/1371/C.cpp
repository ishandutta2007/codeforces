#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T,a,b,n,m;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>a>>b>>n>>m;
        cout<<(min(a,b)>=m&&a+b>=n+m?"Yes\n":"No\n");
    }

    return 0;
}