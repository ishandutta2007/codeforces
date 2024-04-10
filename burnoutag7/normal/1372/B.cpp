#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n,a=1;
        cin>>n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                a=n/i;
                break;
            }
        }
        cout<<a<<' '<<n-a<<endl;
    }

    return 0;
}