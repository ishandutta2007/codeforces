#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[100005],b[100005];
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n,mn=INT_MAX;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
            mn=min(mn,a[i]);
        }
        sort(a+1,a+n+1,cmp);
        int f=1;
        for(int i=1;i<=n;i++)
            if(a[i]!=b[i]&&a[i]%mn)
                f=0;
        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}