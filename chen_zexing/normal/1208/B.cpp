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
int a[2005];
unordered_map <int,int> cnt;
int main() {
    int n,r=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        if(cnt[a[i]]==2) r++;
    }
    if(r==0){
        puts("0");
        return 0;
    }
    int ans;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            cnt[a[j]]--;
            if(cnt[a[j]]==1) r--;
        }
        if(r==0){
            ans=i;
            break;
        }
        for(int j=2;j<=n-i+1;j++){
            cnt[a[j-1]]++;
            if(cnt[a[j-1]]==2) r++;
            cnt[a[j+i-1]]--;
            if(cnt[a[j+i-1]]==1) r--;
            if(r==0){
                ans=i;
                break;
            }
        }
        if(r==0) break;
        cnt.clear();
        r=0;
        for(int j=1;j<=n;j++){
            cnt[a[j]]++;
            if(cnt[a[j]]==2) r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}