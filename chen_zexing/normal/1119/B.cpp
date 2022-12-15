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
int a[1005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,h,f=1,mx=0;
        cin>>n>>h;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            sort(a+1,a+i+1);
            long long now=0;
            for(int j=i;j>=1;j-=2) now+=a[j];
            if(now>h) break;
            else mx=i;
        }
        cout<<mx<<endl;
    }
    return 0;
}