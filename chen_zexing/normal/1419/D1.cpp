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
bool cmp(int a,int b){
    return a<b;
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n/2;i++) b[i*2]=a[i];
    for(int i=n/2+1;i<=n;i++) b[(i-n/2)*2-1]=a[i];
    int cnt=0;
    for(int i=2;i<n;i++) if(b[i]<b[i+1]&&b[i]<b[i-1]) cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}