#include<bits/stdc++.h>
using namespace std;
#define N 200005
char s[N];
struct node{
    int l,r;
    bool operator <(const node z)const{
        return (r-l+1)<(z.r-z.l+1);
    }
}a[N];
void work(){
    int A,B,C,D,n,i,j,m=0,cntA=0;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    n=A+B+(C+D)*2;
    scanf("%s",s+1);
    for(i=1;i<=n;++i){
        if(s[i]=='A')++cntA;
    }
    if(cntA!=A+C+D){
        puts("NO");
        return;
    }
    a[1].l=1;
    m=1;
    for(i=2;i<=n;++i){
        if(s[i]==s[i-1]){
            a[m].r=i-1;
            a[++m].l=i;
        }
    }
    a[m].r=n;
    sort(a+1,a+1+m);
    for(i=1;i<=m;++i){
        if(a[i].l==a[i].r){
            if(s[a[i].l]=='A')--A;
            else --B;
            a[i].l++;
        }
    }
    for(i=1;i<=m;++i){
        if(a[i].l>a[i].r)continue;
        if((a[i].r-a[i].l)&1){
            if(s[a[i].l]=='A'){
                int t=min((a[i].r-a[i].l+1)/2, C);
                C-=t;
                a[i].l+=2*t;
            }
            else{
                int t=min((a[i].r-a[i].l+1)/2, D);
                D-=t;
                a[i].l+=2*t;
            }
        }
    }
    for(i=1;i<=m;++i){
        if(a[i].l>a[i].r)continue;
        if((a[i].r-a[i].l+1)&1){
            int num=(a[i].r-a[i].l+1)/2;
            int cnum=min(num,C);
            C-=cnum;
            num-=cnum;
            int dnum=min(num,D);
            D-=dnum;
            num-=dnum;
            if(s[a[i].l]=='A'){
                a[i].l+=2*cnum;
                a[i].r-=2*dnum;
            }
            else{
                a[i].l+=2*dnum;
                a[i].r-=2*cnum;
            }
        }
        else{
            if(s[a[i].l]=='B'&&C){
                C-=min(C,(a[i].r-a[i].l-1)/2);
            }
            if(s[a[i].l]=='A'&&D){
                D-=min(D,(a[i].r-a[i].l-1)/2);
            }
        }
    }
    if(C+D==0){
        puts("YES");
    }
    else puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}