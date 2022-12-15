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
long long a[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        int f=0;
        long long ans[2]={};
        for(int i=n;i>=1;i--) ans[f]+=(a[i]%2==f)*a[i],f^=1;
        if(ans[0]>ans[1]) puts("Alice");
        else if(ans[0]==ans[1]) puts("Tie");
        else puts("Bob");
    }
    return 0;
}