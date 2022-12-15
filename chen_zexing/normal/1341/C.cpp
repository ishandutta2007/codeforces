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
int a[100005],b[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int x=0,f=1;
        b[++x]=a[1];
        for(int i=1;i<=n;i++){
            if(a[i]<a[i+1]&&i!=n){
                if(a[i]+1!=a[i+1]){
                    f=0;
                    break;
                }
            }
            if(a[i]<a[i-1]) b[++x]=a[i];
        }
        for(int i=1;i<x;i++)
            if(b[i]<b[i+1])
            {
                f=0;
                break;
            }
        if(f) puts("Yes");
        else puts("No");
    }
    return 0;
}