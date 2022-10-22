#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if(a[1] > a[0] && a[1] >= a[2]){
        int temp=a[1];
        a[1]=a[0];
        a[0]=temp;
    } else if(a[2] > a[0] && a[2] >= a[1]){
        int temp=a[2];
        a[2]=a[0];
        a[0]=temp;
    }
    if(a[0]<a[1]+a[2]){
        cout << 0;
        return 0;
    }else cout << a[0]-a[1]-a[2]+1;
    return 0;
}