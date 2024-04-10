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
int a[1005],ans[2];
int main() {
    int n;
    cin>>n;
    int l=1,r=n;
    printf("? ");
    for (int i = 1; i <= n; i++) printf("%d",a[i]);
    puts("");
    fflush(stdout);
    int temp,t;
    scanf("%d",&temp);
    printf("? ");
    a[1]++;
    for (int i = 1; i <= n; i++) printf("%d",a[i]);
    puts("");
    fflush(stdout);
    scanf("%d",&t);
    int g;
    if(temp<t) ans[0]=1,g=0;
    else ans[1]=1,g=1;
    int o=g;
    if(g==1) temp=n-temp;
    for(int i=1;i<=n;i++) a[i]=g;
    g^=1;
    //cout<<temp<<endl;
    while(l<r) {
        int mid=(l+r)>>1;
        printf("? ");
        for(int i=mid+1;i<=r;i++) a[i]=g;
        for (int i = 1; i <= n; i++) printf("%d", a[i]);
        puts("");
        fflush(stdout);
        scanf("%d",&t);
        //cout<<l<<" "<<r<<" "<<g<<endl;
        if(t-temp==r-mid&&g!=o||temp-t==r-mid&&g==o) r=mid;
        else l=mid+1,g^=1;
        temp=t;
    }
    for(int i=0;i<2;i++) if(!ans[i]) ans[i]=l;
    printf("! %d %d\n",ans[0],ans[1]);
    return 0;
}