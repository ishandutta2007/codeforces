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
int a[300005],cnt[300005],b[300005];
int main() {
    int n,x=0;
    cin>>n;
    long long sum=0,r=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i],cnt[a[i]]++;
    for(int i=300000;i>=1;i--) if(cnt[i]%2) b[++x]=i;
    for(int i=1;i<=x;i++){
        //cout<<b[i]<<" ";
        if(b[i]%2){
            if(i%2) r++;
            else r--;
        }
    }
    cout<<(sum-abs(r))/2<<endl;
    return 0;
}