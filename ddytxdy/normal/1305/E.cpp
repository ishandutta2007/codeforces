#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,mx,p,a[N],re;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        mx+=(i-1)/2;if(mx<=m)p=i,re=m-mx;
    }
    if(m>mx)puts("-1"),exit(0);
    for(int i=1;i<=p;i++)a[i]=i;
    a[p+1]=2*p+1-2*re;a[p+2]=1e8;
    for(int i=p+3;i<=n;i++)a[i]=a[i-1]+10010;
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}