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
int a[300005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int mx=0;
        for(int i=n;i>=1;i--) if(a[i]!=a[1]) mx=max(mx,i-1);
        for(int i=1;i<=n;i++) if(a[i]!=a[n]) mx=max(mx,n-i);
        cout<<mx<<endl;
    }
    return 0;
}