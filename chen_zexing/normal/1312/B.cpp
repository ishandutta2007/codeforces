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
int a[105],b[105];
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}