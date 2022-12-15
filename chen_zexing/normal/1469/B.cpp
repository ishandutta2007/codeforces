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
int a[105],b[105];
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        cin>>m;
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int mx1=0,mx2=0,sum=0;
        for(int i=1;i<=n;i++) sum+=a[i],mx1=max(mx1,sum);
        sum=0;
        for(int i=1;i<=m;i++) sum+=b[i],mx2=max(mx2,sum);
        cout<<mx1+mx2<<endl;
    }
    return 0;
}