#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1010;
int n,m,a[N],p[N],ans;char s[N];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int ask(){
    int x;
    printf("? %s\n",s+1);
    cout.flush();
    scanf("%d",&x);
    return x;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)s[i]='0';
    for(int i=1;i<=m;i++){
        s[i]='1';
        a[i]=ask();
        s[i]='0';
    }
    for(int i=1;i<=m;i++)p[i]=i;
    sort(p+1,p+m+1,cmp);
    for(int i=1;i<=m;i++)s[i]='1';
    ans=ask();
    for(int i=1;i<m;i++){
        int x=p[i];
        s[x]='0';
        int now=ask();
        if(now!=ans-a[x]){
            ans=now;
        }
        else{
            s[x]='1';
        }
    }
    printf("! %d\n",ans);
    cout.flush();
    return 0;
}