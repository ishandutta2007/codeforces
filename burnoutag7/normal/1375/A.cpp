#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            cout<<abs(a[i])*((i&1)?1:-1)<<' ';
        }
        cout<<endl;
    }

    return 0;
}