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
    int T=1;
    cin>>T;
    while(T--){
        int A,B;
        int n;
        cin>>A>>B>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        long long tot=0;
        for(int i=1;i<=n;i++){
            int t=b[i]/A+(b[i]%A>0);
            //t--;
            tot+=1LL*t*a[i];
        }
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,a[i]);
        if(tot-mx<B) puts("YES");
        else puts("NO");
    }
    return 0;
}