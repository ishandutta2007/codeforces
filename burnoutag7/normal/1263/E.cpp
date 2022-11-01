#include<bits/stdc++.h>
using namespace std;

int n,sz,pos,rm;
char s[1000005];
char op[1000005];
int datamax[4000005];
int datamin[4000005];
int lazy[4000005];

inline void pushdown(const int &bk){
    int &cur=lazy[bk];
    lazy[bk<<1]+=cur;
    datamax[bk<<1]+=cur;
    datamin[bk<<1]+=cur;
    lazy[bk<<1|1]+=cur;
    datamax[bk<<1|1]+=cur;
    datamin[bk<<1|1]+=cur;
    cur=0;
}

void upd(int bk,int l,int r,int ql,int qr,int val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        lazy[bk]+=val;
        datamax[bk]+=val;
        datamin[bk]+=val;
        return;
    }
    pushdown(bk);
    upd(bk<<1,l,(l+r)>>1,ql,qr,val);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr,val);
    datamin[bk]=min(datamin[bk<<1],datamin[bk<<1|1]);
    datamax[bk]=max(datamax[bk<<1],datamax[bk<<1|1]);
}

int qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr){
        return datamin[bk];
    }
    pushdown(bk);
    return min(qry(bk<<1,l,(l+r)>>1,ql,qr),qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr));
}

int main(){

    scanf("%d\n",&n);
    gets(op);
    pos=1;rm=1;
    for(int i=0;i<n;i++){
        if(op[i]=='L'){
            if(pos>1)pos--;
        }else
        if(op[i]=='R'){
            pos++;
            rm=max(rm,pos);
        }
    }
    sz=1;while(sz<rm)sz<<=1;
    pos=1;
    for(int i=0;i<n;i++){
        if(op[i]=='L'){
            if(pos>1)pos--;
        }else
        if(op[i]=='R'){
            pos++;
        }else{
            if(s[pos]=='('){
                if(op[i]=='('){
                    //upd(1,1,sz,pos,rm,0);
                }else
                if(op[i]==')'){
                    upd(1,1,sz,pos,rm,-2);
                }else{
                    upd(1,1,sz,pos,rm,-1);
                }
            }else
            if(s[pos]==')'){
                if(op[i]=='('){
                    upd(1,1,sz,pos,rm,2);
                }else
                if(op[i]==')'){
                    //upd(1,1,sz,pos,rm,0);
                }else{
                    upd(1,1,sz,pos,rm,1);
                }
            }else{
                if(op[i]=='('){
                    upd(1,1,sz,pos,rm,1);
                }else
                if(op[i]==')'){
                    upd(1,1,sz,pos,rm,-1);
                }
            }
            s[pos]=op[i];
        }
        if(datamin[1]<0||qry(1,1,sz,rm,rm)||datamax[rm+sz-1]){
            printf("-1 ");
        }else{
            printf("%d ",datamax[1]);
        }
    }

    return 0;
}