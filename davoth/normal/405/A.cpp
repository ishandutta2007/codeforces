#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int o=0;o<i;o++){
            if(a[o]>a[i]){
                int d=a[o]-a[i];
                a[i]+=d;
                a[o]-=d;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}