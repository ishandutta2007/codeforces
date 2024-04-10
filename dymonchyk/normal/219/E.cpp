#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

const int BLOCK=1400,TOT=210000;
int in[TOT/BLOCK],l[TOT/BLOCK],r[TOT/BLOCK],bs[TOT/BLOCK],pl[TOT/BLOCK],pr[TOT/BLOCK];
int wh[1000002],on[200002],n;

int getPos(int l,int r) {
    if (l==0) return 0;
    if (r==n-1) return n-1;
    return (l+r)>>1;
}

inline int dist(int l,int r) {
    if (l==0||r==n-1) return r-l+1;
    int pos=(l+r)>>1;
    return min(pos-l+1,r-pos+1);
}

inline bool cool(int cl,int cr,int l,int r) {
    if (r-l+1<=0) return cl<=cr;
    int d1=dist(cl,cr),d2=dist(l,r);
    return d1>d2||d1==d2&&cl<l;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int m,t,id;
    scanf("%d%d",&n,&m);
    int bcnt=0,tmp=n,s=0;
    for(;tmp;) {
        bs[bcnt++]=min(BLOCK,tmp);
        tmp-=bs[bcnt-1];
        in[bcnt-1]=l[bcnt-1]=r[bcnt-1]=bs[bcnt-1];
        pl[bcnt-1]=s; pr[bcnt-1]=s+bs[bcnt-1]-1;
        s+=bs[bcnt-1];
    }
    for(int e=0;e<m;++e) {
        scanf("%d%d",&t,&id);
        int pos,s=0;
        if (t==1) {
            int L=0,R=-1,cl=0,cr=-1,tot=0;
            for(int i=0;i<bcnt;++i) {
                if (in[i]==bs[i]) {
                    cr+=in[i];
                    if (cool(cl,cr,L,R)) R=cr,L=cl;
                }
                else {
                    cr+=l[i];
                    if (cool(cl,cr,L,R)) R=cr,L=cl;
                    cl=tot+bs[i]-r[i]; cr=tot+bs[i]-1;
                    if (cool(cl,cr,L,R)) R=cr,L=cl;
                }
                tot+=bs[i];
                if (cool(pl[i],pr[i],L,R)) L=pl[i],R=pr[i];
            }
            pos=getPos(L,R);
            wh[id]=pos; on[pos]=id;
            printf("%d\n",pos+1);
        } else {
            pos=wh[id]; on[wh[id]]=0; wh[id]=0;
        }
        for(int i=0;i<bcnt;++i) {
            if (s<=pos&&pos<s+bs[i]) {
                int f=0; pl[i]=0; pr[i]=-1;
                for(int j=0;j<bs[i];++j) {
                    if (on[s+j]) break;
                    ++f;
                }
                l[i]=f;
                if (f) pl[i]=s,pr[i]=s+f-1;
                f=0; int beg=s;
                for(int j=0;j<bs[i];++j) {
                    if (on[s+j]) {
                        if (cool(beg,beg+f-1,pl[i],pr[i])) pl[i]=beg,pr[i]=beg+f-1;
                        beg=s+j+1; f=0;
                    } else f++;
                }
                f=0;
                for(int j=0;j<bs[i];++j) {
                    if (on[s+bs[i]-1-j]) break;
                    ++f;
                }
                r[i]=f;
                if (cool(s+bs[i]-f,s+bs[i]-1,pl[i],pr[i])) pl[i]=s+bs[i]-f,pr[i]=s+bs[i]-1;
                in[i]=pr[i]-pl[i]+1;
                break;
            } else s+=bs[i];
        }
    }
    return 0;
}