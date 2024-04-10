#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n,k,im=0,m;
    cin>>n>>k;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int sum;
    for(int i=0;i<k;i++){
        sum+=h[i];
    }
    m=sum;
    for(int i=k;i<n;i++){
        sum+=h[i];
        sum-=h[i-k];
        if(sum<m){
            m=sum;
            im=i-k+1;
        }
    }
    cout<<im+1;
    return 0;
}