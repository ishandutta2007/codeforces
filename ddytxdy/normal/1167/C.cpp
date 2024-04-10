#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+50;
int n,m,num,x,la,f[N],s[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        for(int i=1;i<=num;i++){
            scanf("%d",&x);
            if(i>1){
                int fx=find(x),fy=find(la);
                if(fx!=fy)f[fx]=fy,s[fy]+=s[fx];
            }
            la=x;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",s[find(i)]);
    return 0;
}