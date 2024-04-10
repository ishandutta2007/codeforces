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
int a[300005],f[300005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=0;
        int sum=0;
        for(int i=2;i<n;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1]) sum++,f[i]=1;
            else if(a[i]<a[i-1]&&a[i]<a[i+1]) sum++,f[i]=2;
        }
        int mx=0;
        for(int i=2;i<n;i++){
            int c=(f[i]>0),temp;
            temp=a[i-1];
            if(f[i-1]) c++;
            if(f[i+1]==2&&temp<=a[i+1]||f[i+1]==1&&temp>=a[i+1]) c++;
            else if(!f[i+1]&&(i+1!=n)&&(a[i+1]>a[i+2]&&a[i+1]>temp||a[i+1]<a[i+2]&&a[i+1]<temp)) c--;
            mx=max(mx,c);
            //cout<<mx<<" "<<i<<endl;
            c=(f[i]>0),temp=a[i+1];
            if(f[i+1]) c++;
            if(f[i-1]==2&&temp<=a[i-1]||f[i-1]==1&&temp>=a[i-1]) c++;
            else if(!f[i-1]&&(i-1!=1)&&(a[i-1]>a[i-2]&&a[i-1]>temp||a[i-1]<a[i-2]&&a[i-1]<temp)) c--;
            mx=max(mx,c);
            //cout<<mx<<" "<<i<<endl;
        }
        printf("%d\n",max(0,sum-mx));
    }
    return 0;
}