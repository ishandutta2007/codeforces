#include<bits/stdc++.h>
using namespace std;

int T,n,x;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>x;
        cout<<(n<=2?1:(n-2+x-1)/x+1)<<endl;
    }

    return 0;
}