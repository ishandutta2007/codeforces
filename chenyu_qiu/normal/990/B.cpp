#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[1000000+10];
int main() {
    int n,K;
    cin>>n>>K;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int cnt = 0;
    int c = 1;
    for(int i=1;i<n;i++) {
        if(a[i]==a[i-1]) c+=1;
        else if(a[i]<=a[i-1]+K) cnt+=c,c=1;
        else c=1;
    }
    cout<<n-cnt<<endl;
    return 0;
}