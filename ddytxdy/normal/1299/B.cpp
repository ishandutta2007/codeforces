#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n;
struct node{
    int x,y;
    node operator -(const node &b){return (node){x-b.x,y-b.y};}
    LL operator *(const node &b){return 1ll*x*b.y-1ll*y*b.x;}
    LL sqr(){return 1ll*x*x+1ll*y*y;}
}a[N],b[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&b[i].x,&b[i].y);
    for(int i=1;i<n;i++)a[i]=b[i+1]-b[i];a[n]=b[1]-b[n];
    for(int i=1,j=i+1;i<=n;i++){
        while(a[i]*a[j]>0)j=j%n+1;
        if(a[j]*a[i])puts("NO"),exit(0);
        if(a[i].sqr()!=a[j].sqr())puts("NO"),exit(0);
    }
    puts("YES");
}