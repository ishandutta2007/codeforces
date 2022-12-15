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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[5005];
int solve(int l,int r){
    int mn=INT_MAX,ans=r-l+1,pos;
    for(int i=l;i<=r;i++){
        if(mn>a[i]) mn=a[i],pos=i;
    }
    for(int i=l;i<=r;i++) a[i]-=mn;
    int st=l,temp=mn;
    for(int i=l;i<=r+1;i++){
        if(a[i]==0){
            if(st!=i) temp+=solve(st,i-1);
            st=i+1;
        }
    }
    return min(ans,temp);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<solve(1,n)<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp