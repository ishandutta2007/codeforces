#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],b[N],p[N],f[N],num;
void add(int x){for(;x<=n;x+=x&-x)f[x]++;}
int ask(int x){int y=0;for(;x;x-=x&-x)y+=f[x];return y;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=i;
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=n;i;i--){
        if(ask(p[b[i]]))num++;
        add(p[b[i]]);
    }
    printf("%d\n",num);
    return 0;
}