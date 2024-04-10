//
// Created by calabash_boy on 18-7-13.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],n;
int rk[maxn];
bool cmp(int x,int y){
    return a[x]<a[y];
}
bool used[maxn];
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
        rk[i]=i;
    }
    sort(a,a+n);
    int ans =0;
    for (int i=0,j=1;i<n;i++){
        while (j<n&&a[j]==a[i])j++;
        if (j<n){
            ans++;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}