#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k,a;
    cin>>n>>k;
    int l[n];
    cin>>l[0];
    int max=l[0],min=l[0];
    for(int i=1;i<n;i++){
        cin>>l[i];
        if(l[i]>max){
            max=l[i];
        }
        if(l[i]<min){
            min=l[i];
        }
    }
    if(k==1){
        cout<<min;
        return 0;
    }else if(k>2){
        cout<<max;
        return 0;
    }else{
        if(l[0]>l[n-1]){
            cout<<l[0];
        }else{
            cout<<l[n-1];
        }
    }

    return 0;
}