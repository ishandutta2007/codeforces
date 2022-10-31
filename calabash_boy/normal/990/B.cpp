//
// Created by calabash_boy on 18-6-11.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int a[maxn];
bool used[maxn];
int k,n;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    for (int i=0,j=0;i<n;i++){
        while (j<i&&a[j]<a[i]-k)j++;
        while (j<i&&a[i]!=a[j])used[j]=1,j++;
    }
    int ans =0;
    for (int i=0;i<n;i++){
        ans+=used[i]!=1;
    }
    cout<<ans<<endl;
    return 0;
}