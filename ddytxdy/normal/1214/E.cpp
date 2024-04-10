#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,d[N],b[N*2],tot;
struct node{
    int x,y,d;
    bool friend operator <(node a,node b){return a.d>b.d;}
}a[N];
vector<int>v[N*2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].d),a[i].x=i*2,a[i].y=i*2-1;
    sort(a+1,a+n+1);
    tot=n;
    for(int i=1;i<=n;i++){
        b[i]=a[i].x;
        if(i+a[i].d>tot)tot=i+a[i].d,b[tot]=a[i].y;
        else v[i+a[i].d-1].push_back(a[i].y);
    }
    for(int i=1;i<tot;i++)printf("%d %d\n",b[i],b[i+1]);
    for(int i=1;i<=tot;i++)
        for(int j=0;j<v[i].size();j++)
            printf("%d %d\n",b[i],v[i][j]);
    return 0;
}