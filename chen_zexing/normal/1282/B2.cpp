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
int a[200005],mn[200005];
bool cmp(int a,int b){
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k,p;
        cin>>n>>p>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        int i;
        for(i=1;i<=n;i++){
            if(i>=k) mn[i]=mn[i-k]+a[i];
            else mn[i]=mn[i-1]+a[i];
        }
        for(i=n;i>=1;i--)
            if(mn[i]<=p)
                break;
        cout<<i<<endl;
    }
    return 0;
}