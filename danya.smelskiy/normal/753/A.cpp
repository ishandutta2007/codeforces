#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin>>n;
    int l=1;
    int r=1000;
    while (l<r-1){
        int mid=(l+r)/2;
        int x=(mid)*(mid+1)/2;
        if (x>n) r=mid;
        else l=mid;
    }
    cout<<l<<'\n';
    for (int i=1;i<l;++i)
        cout<<i<<" ";
    int x=(l-1)*(l)/2;
    cout<<n-x;
}