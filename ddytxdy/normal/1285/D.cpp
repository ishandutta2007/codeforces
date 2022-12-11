#include<bits/stdc++.h>
using namespace std;
const int N=4e6+50;
int n,c[N][2],tot;
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
void insert(int x){
    for(int i=29,p=0,y;~i;i--){
        if(!c[p][y=x>>i&1])c[p][y]=++tot;
        p=c[p][y];
    }
}
int solve(int p,int d){
    if(d<0)return 0;
    if(!c[p][0])return solve(c[p][1],d-1);
    if(!c[p][1])return solve(c[p][0],d-1);
    return min(solve(c[p][0],d-1),solve(c[p][1],d-1))^1<<d;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)insert(read());
    printf("%d\n",solve(0,29));
}