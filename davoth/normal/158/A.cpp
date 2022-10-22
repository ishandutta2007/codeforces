#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int l[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    int c=l[k-1],cnt=0;
    for(int i=0;i<n;i++){
        if(l[i]>=c&&l[i]!=0) cnt++;
    }
    cout<<cnt;
    return 0;
}