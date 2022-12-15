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
using namespace std;
int a[55],b[55];
bool cmp(int a,int b){
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        int f=1;
        for(int i=1;i<=n;i++)
            if(a[i]+b[n-i+1]>x)
                f=0;
        if(f) puts("Yes");
        else puts("No");
    }
    return 0;
}