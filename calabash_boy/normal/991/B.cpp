#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int n;
int sum =0;
bool check(){
    double temp = 1.0*sum/n+0.5;
    int av = (int)temp;
    if(av==5)return true;
    return false;
}
int main() {
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    if(check()){
        cout<<0<<endl;
        return 0;
    }
    int ans =0;
    for (int i=0;i<n;i++){
        sum+=5-a[i];
        if(check()){
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}