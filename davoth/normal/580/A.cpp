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
    int m=1;
    for(int i=0;i<n;i++){
        int c=1;
        for(int o=i+1;o<n;o++){
            if(a[o]>=a[o-1]){
                c++;
            }else{
                break;
            }
        }
        if(c>m) m=c;
        if(m>=n-i){
            break;
        }
    }
    cout<<m;
    return 0;
}