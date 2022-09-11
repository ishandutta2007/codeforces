#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int sqr(int x){return x*x;}
struct data{
    int x,r,No;
    bool operator<(data b)const{
        return x<b.x;
    }
    bool in(int x2,int y2){
        return r*r>=sqr(x2-x)+sqr(y2);
    }
}a[10000];
int an[10001];
int Bsearch(int x,int n){
    int l=-1,r=n-1,mid;
    while(l<r){
        mid=(l+r+3)/2-1;
        if(a[mid].x>x)r=mid-1;
        else l=mid;
    }
    return l;
}
main(){
    int n,i,j,x,y,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].r);
        a[i].No=i+1;
    }
    sort(a,a+n);
    for(i=1;i<=n;i++)an[i]=-1;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        j=Bsearch(x,n);
        if(j>=0){
            if(a[j].in(x,y)&&an[a[j].No]==-1)an[a[j].No]=i;
        }
        if(j+1<n){
            if(a[j+1].in(x,y)&&an[a[j+1].No]==-1)an[a[j+1].No]=i;
        }
    }
    j=0;
    for(i=1;i<=n;i++)
        if(an[i]!=-1)j++;
    printf("%d\n",j);
    for(i=1;i<=n;i++){
        if(i!=1)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");

}