#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<"\n"<<a[0];
        return 0;
    }
    int s=0;
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1]<k){
            s+=k-a[i]-a[i-1];
            a[i]=k-a[i-1];
        }
    }
    cout<<s<<"\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}