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
int a[1005],ans[1005],f[1005];
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n,x=0,now=1,c;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) f[i]=1;
        f[1]=0;
        sort(a+1,a+n+1,cmp);
        c=a[1];
        ans[++x]=a[1];
        while(x<n){
            int p,mx=0;
            for(int i=1;i<=n;i++){
                if(f[i]&&mx<gcd(a[i],c)){
                    mx=gcd(a[i],c);
                    p=i;
                }
            }
            f[p]=0;
            ans[++x]=a[p];
            c=mx;
            //cout<<c<<" "<<p<<endl;
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}