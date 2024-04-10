#include<iostream>
using namespace std;
#define ll long long
int a[200005];
int main(){
    int t,n,i,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        if(k==1){
            cout<<(n-1)/2<<endl;
            continue;
        }
        int sum=0;
        //
        for(i=2;i<=n-1;i++){
            ll t=a[i-1]+a[i+1];
            if(a[i]>t){
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}