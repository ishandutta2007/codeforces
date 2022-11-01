#include<bits/stdc++.h>
using namespace std;

int t,n,k1,k2;
int a[105],b[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k1>>k2;
        a[0]=0;
        for(int i=1;i<=k1;i++){
            cin>>a[i];a[0]=max(a[0],a[i]);
        }
        b[0]=0;
        for(int i=1;i<=k2;i++){
            cin>>b[i];b[0]=max(b[0],b[i]);
        }
        cout<<(a[0]>b[0]?"YES":"NO")<<endl;
    }

    return 0;
}