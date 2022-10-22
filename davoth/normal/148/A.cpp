#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    int a[d]={0};
    int cnt=0;
    for(int i=k-1;i<d;i+=k){
        if(a[i]==0){
            a[i]++;
            cnt++;
        }
    }
    for(int i=l-1;i<d;i+=l){
        if(a[i]==0){
            a[i]++;
            cnt++;
        }
    }
    for(int i=m-1;i<d;i+=m){
        if(a[i]==0){
            a[i]++;
            cnt++;
        }
    }
    for(int i=n-1;i<d;i+=n){
        if(a[i]==0){
            a[i]++;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}