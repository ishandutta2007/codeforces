#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    for(int i=0;i<n-2;i++){
        if(l[i+1]+l[i]>l[i+2]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}