/*
 * @Author: BilyHurington
 * @Date: 2020-07-26 22:46:20
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-26 23:44:18
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,rt,a[100010];
mt19937 myrand(time(NULL));
struct node{
    int ch[2],siz;unsigned int rnd;
    long long val,A,B;//Ax+B
}p[100010];
void add(int k,long long A,long long B){
    p[k].A+=A;p[k].B+=B;
    p[k].val+=(p[p[k].ch[0]].siz+1)*A+B;
}
void upt(int x){p[x].siz=p[p[x].ch[0]].siz+p[p[x].ch[1]].siz+1;}
void push_down(int k){
    if(!p[k].A&&!p[k].B) return;
    if(p[k].ch[0]) add(p[k].ch[0],p[k].A,p[k].B);
    if(p[k].ch[1]) add(p[k].ch[1],p[k].A,p[k].B+(p[p[k].ch[0]].siz+1)*p[k].A);
    p[k].A=p[k].B=0;
}
void split(int k,int &x,int &y,int sz){
    if(!k){x=y=0;return;}
    push_down(k);
    if(p[p[k].ch[0]].siz>=sz){
        y=k;
        split(p[k].ch[0],x,p[y].ch[0],sz);
    }
    else{
        x=k;
        split(p[k].ch[1],p[x].ch[1],y,sz-p[p[k].ch[0]].siz-1);
    }
    upt(k);
}
int merge(int x,int y){
    if(!x||!y) return x|y;
    push_down(x);push_down(y);
    if(p[x].rnd<p[y].rnd){p[x].ch[1]=merge(p[x].ch[1],y);upt(x);return x;}
    else{p[y].ch[0]=merge(x,p[y].ch[0]);upt(y);return y;}
}
long long get_val(int x){
    int k=rt;
    // printf("GET %d: ",x);
    while(k){
        // printf("%d ",k);
        push_down(k);
        if(p[p[k].ch[0]].siz>=x) k=p[k].ch[0];
        else if(p[p[k].ch[0]].siz+1==x){break;}
        else x-=p[p[k].ch[0]].siz+1,k=p[k].ch[1];
    }
    // printf("\n");
    return p[k].val;
}
long long get_ans(int k){
    if(!k) return -1e18;
    push_down(k);
    return max(p[k].val,max(get_ans(p[k].ch[0]),get_ans(p[k].ch[1])));
}
void output(int k){
    if(!k) return;
    push_down(k);
    output(p[k].ch[0]);
    printf("%lld %d\n",p[k].val,p[k].siz);
    output(p[k].ch[1]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int tot=1;p[1].siz=1;rt=1;p[1].rnd=myrand();
    int rt1,rt2;
    for(int i=1;i<=n;i++){
        int l=0,r=i-1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(get_val(mid+1)+1ll*(mid+1)*a[i]>get_val(mid+2)) r=mid;
            else l=mid+1;
        }
        // printf("%d\n",l);
        long long val=get_val(l+1);
        // printf("%lld\n",val);
        p[++tot].siz=1;p[tot].val=val;p[tot].rnd=myrand();
        split(rt,rt1,rt,l+1);rt=merge(tot,rt);
        add(rt,a[i],1ll*a[i]*l);
        rt=merge(rt1,rt);
        // output(rt);printf("\n");
    }
    printf("%lld",get_ans(rt));
    return 0;
}