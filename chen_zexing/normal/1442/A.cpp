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
int a[30005],l[30005],r[30005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        l[0]=r[n+1]=INT_MAX;
        for(int i=1;i<=n;i++){
            l[i]=min(l[i-1],a[i]-r[i-1]);
            r[i]=a[i]-l[i];
        }
        int f=1;
        for(int i=1;i<=n;i++) if(r[i]>r[i+1]||l[i]<0) f=0;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}