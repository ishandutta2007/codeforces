#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[505],f[505];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int len=r-l+1;
        if(s>(n+(n-len+1))*len/2||s<(len+1)*len/2){
            puts("-1");
            continue;
        }
        int now=(len+1)*len/2;
        for(int i=l;i<=r;i++) a[i]=i-l+1;
        int temp=r;
        while(now<s){
            if(a[temp]<n&&(a[temp]<a[temp+1]-1||temp==r)) a[temp]++,now++;
            else{
                temp--;
                a[temp]++,now++;
            }
        }
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=l;i<=r;i++) f[a[i]]=1;
        int t=1;
        for(int i=1;i<=n;i++){
            if(i<l||i>r){
                while(f[t]) t++;
                a[i]=t++;
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp