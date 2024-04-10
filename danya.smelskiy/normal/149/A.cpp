#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[100001];

bool cmp(int a,int b){
    return (a>b);
}
int main(){
    cin>>n;
    for (int i=1;i<=12;++i)
        cin>>a[i];
    sort(a+1,a+12+1,cmp);
    for (int i=0;i<=12;++i){
        ans+=a[i];
        if (ans>=n) {
            cout<<i;
            return 0;
        }}
        cout<<"-1";
}