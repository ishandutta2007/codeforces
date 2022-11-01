#include<bits/stdc++.h>
using namespace std;

int t,n,a[200005],p;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;p=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            if(abs(a[i]-a[i+1])>1)p=i;
        }
        if(!p){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<p<<' '<<p+1<<endl;
        }
    }

    return 0;
}