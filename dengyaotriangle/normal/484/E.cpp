#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!
struct qios{static const int rsiz=2.1e6,wsiz=1.1e6;static const char end=-1;inline char gc(){static char buf[rsiz],*s,*t;return (s==t)&&(t=(s=buf)+fread(buf,1,rsiz,stdin)),s==t?-1:*s++;}inline void pc(char c){static char buf[wsiz],*t=buf;c==-1?fwrite(buf,t-buf,1,stdout):*t++=c;}inline qios&operator>>(char&x){x=gc();while(!isgraph(x)){if(x==-1)return *this;x=gc();}return *this;}template<typename t>inline qios&operator>>(t&x){static char ch;static bool sgn;ch=gc();sgn=0;for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}for(x=0;isdigit(ch);ch=gc()){x=x*10+(ch^'0');}sgn&&(x=-x);return *this;}inline qios&operator<<(char x){pc(x);return *this;}inline qios&operator<<(const char*x){while(*x)pc(*(x++));return *this;}template<typename t>inline qios&operator<<(t x){static char buf[30];static int pt;pt=0;if(x<0){pc('-');x=-x;}if(x==0)buf[pt++]='0';while(x){buf[pt++]='0'|(x%10);x/=10;}while(pt)pc(buf[--pt]);return *this;}}qio;

const int maxn=100005;

struct node{
    int l,r;
    int lv,rv,tv;
    node* c[2];
}pool[maxn*50];int ps;

inline node* nwnode(int l,int r){
    node* nw=pool+ps++;
    nw->l=l;nw->r=r;nw->lv=nw->rv=nw->tv=0;nw->c[0]=nw->c[1]=NULL;
    return nw;
}
inline node* cpnode(node*rt){
    node* nw=pool+ps++;*nw=*rt;return nw;
}
inline void pu(node* rt){
    if(rt->l!=rt->r){
        rt->lv=rt->c[0]->lv==rt->c[0]->r-rt->c[0]->l+1?rt->c[0]->r-rt->c[0]->l+1+rt->c[1]->lv:rt->c[0]->lv;
        rt->rv=rt->c[1]->rv==rt->c[1]->r-rt->c[1]->l+1?rt->c[1]->r-rt->c[1]->l+1+rt->c[0]->rv:rt->c[1]->rv;
        rt->tv=max(rt->c[0]->rv+rt->c[1]->lv,max(rt->c[0]->tv,rt->c[1]->tv));
    }
}
node* bt(int l,int r){
    node* nw=nwnode(l,r);
    if(l!=r){nw->c[0]=bt(l,(l+r)>>1);nw->c[1]=bt(((l+r)>>1)+1,r);pu(nw);}
    return nw;
}
void chg(node* rt,int i){
    int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
    if(cl==cr)rt->lv=rt->rv=rt->tv=1;
    else if(i<=cm){rt->c[0]=cpnode(rt->c[0]);chg(rt->c[0],i);}
    else{rt->c[1]=cpnode(rt->c[1]);chg(rt->c[1],i);}
    pu(rt);
}

node qry(node* rt,int l,int r){
    int cl=rt->l,cr=rt->r,cm=(cl+cr)>>1;
    if(l==cl&&r==cr)return *rt;
    else if(r<=cm)return qry(rt->c[0],l,r);
    else if(l>cm)return qry(rt->c[1],l,r);
    else{
        node f1=qry(rt->c[0],l,cm),f2=qry(rt->c[1],cm+1,r),f3;
        f3.c[0]=&f1;f3.c[1]=&f2;f3.r=f2.r;f3.l=f1.l;pu(&f3);
        return f3;
    }
}

int n;
int h[maxn];
int mh[maxn];
int cnt=0;
pair<int,int> dsc[maxn];
vector<int> p[maxn];
node* rt[maxn];

inline bool chk(int l,int r,int k,int g){
    return qry(rt[k],l,r).tv>=g;
}
inline int calc(int cl,int cr,int k){
    int l=1,r=cnt;
    while(r-l>2){
        int m=(l+r)>>1;
        chk(cl,cr,m,k)?l=m:r=m;
    }
    for(int i=r;i>=l;i--){if(chk(cl,cr,i,k))return mh[i];}
}

int main(){
    qio>>n;
    for(int i=1;i<=n;i++){
        qio>>h[i];dsc[i].first=h[i];dsc[i].second=i;
    }
    sort(dsc+1,dsc+1+n);
    for(int i=1;i<=n;i++){
        if(i==1||dsc[i].first!=dsc[i-1].first)cnt++;
        mh[cnt]=dsc[i].first;h[dsc[i].second]=cnt;
    }
    for(int i=1;i<=n;i++){p[h[i]].push_back(i);}
    rt[cnt+1]=bt(1,n);
    for(int i=cnt;i>=1;i--){
        rt[i]=cpnode(rt[i+1]);
        for(int j=0;j<p[i].size();j++){chg(rt[i],p[i][j]);}
    }
    int q;qio>>q;
    while(q--){
        int l,r,k;
        qio>>l>>r>>k<<calc(l,r,k)<<'\n';
    }
    qio<<qios::end;
    return 0;
}