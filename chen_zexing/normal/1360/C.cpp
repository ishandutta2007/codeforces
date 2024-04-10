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
int a[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        int cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i]%2;
        sort(a+1,a+n+1);
        int f=0;
        for(int i=1;i<n;i++) if(a[i]==a[i+1]-1) f=1;
        if(cnt%2==0){
            puts("YES");
        }
        else if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}