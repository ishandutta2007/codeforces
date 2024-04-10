#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n,m,b=9999;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a,a+m);
    for(int i=0;i<m-n+1;i++){
        if(a[i+n-1]-a[i]<b) b=a[i+n-1]-a[i];
    }
    cout<<b;
    return 0;
}