#include<iostream>
using namespace std;
int a[100];
int main(){
    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<a[0]<<endl;
    }
    return 0;
}