#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 200500
#define MAX 1000000001
#define MM 500
int s[SIZE],f[SIZE],t[SIZE],l[SIZE],r[SIZE],b[SIZE],a[SIZE*4],rr,an[SIZE];
struct haha{
    int x,y;
    haha(int _x=0,int _y=0){x=_x,y=_y;}
    bool operator<(const haha& b)const{return x<b.x;}
};
set<haha>arrive[SIZE+SIZE],group_arrive[2*SIZE/MM];
struct data{
    int r,l,t,ty,No;
    bool operator<(const data& b)const{return r>b.r||(r==b.r&&ty<b.ty);}
}d[SIZE+SIZE];
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>s[i]>>f[i]>>t[i];
    for(i=0;i<m;i++)cin>>l[i]>>r[i]>>b[i];
    rr=0;
    for(i=0;i<n;i++){
        a[rr++]=s[i];
        a[rr++]=f[i];
    }
    for(i=0;i<m;i++){
        a[rr++]=l[i];
        a[rr++]=r[i];
    }
    sort(a,a+rr);
    rr=unique(a,a+rr)-a;
    for(i=0;i<n;i++)s[i]=lower_bound(a,a+rr,s[i])-a;
    for(i=0;i<n;i++)f[i]=lower_bound(a,a+rr,f[i])-a;
    for(i=0;i<m;i++)l[i]=lower_bound(a,a+rr,l[i])-a;
    for(i=0;i<m;i++)r[i]=lower_bound(a,a+rr,r[i])-a;

    rr=0;
    for(i=0;i<n;i++)
        a[rr++]=t[i];
    for(i=0;i<m;i++)
        a[rr++]=b[i];
    sort(a,a+rr);
    rr=unique(a,a+rr)-a;
    for(i=0;i<n;i++)t[i]=lower_bound(a,a+rr,t[i])-a;
    for(i=0;i<m;i++)b[i]=lower_bound(a,a+rr,b[i])-a;
    for(i=0;i<n;i++){
        d[i]=(data){f[i],s[i],t[i],0,i};
    }
    for(i=0;i<m;i++){
        d[n+i]=(data){r[i],l[i],b[i],1,i};
    }
    n=n+m;
    sort(d,d+n);
    for(i=0;i<n;i++){
        if(!d[i].ty){
            int now=d[i].l;
            arrive[now].insert((haha){d[i].t,d[i].No+1});
            group_arrive[now/MM].insert((haha){d[i].t,d[i].No+1});
        }
        else{
            int now=d[i].l;
            int now2=now/MM;
            int mi=MAX,res=-1;
            for(j=0;j<now2;j++){
                set<haha>::iterator it=group_arrive[j].lower_bound(d[i].t);
                if(it!=group_arrive[j].end()){
                    if(mi>it->x){
                        mi=it->x;
                        res=it->y;
                    }
                }
            }
            for(j=now2*MM;j<=now;j++){
                set<haha>::iterator it=arrive[j].lower_bound(d[i].t);
                if(it!=arrive[j].end()){
                    if(mi>it->x){
                        mi=it->x;
                        res=it->y;
                    }
                }
            }
            an[d[i].No]=res;
        }

    }
    for(i=0;i<m;i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}