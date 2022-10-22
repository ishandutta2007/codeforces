#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=200000,C=21,inf=(1<<30)-1;
const int64 INF=(1LL<<60)-1;

int n;
struct point{
  int x,y;
  point(int X=0,int Y=0):x(X),y(Y){}
}a[N+9];

void In(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
    scanf("%d%d",&a[i].x,&a[i].y);
}

bool cmp_x(const point &a,const point &b){return a.x<b.x;}
bool cmp_y(const point &a,const point &b){return a.y<b.y;}

int m_x,m_y;
int64 ans;

void Get_m(){
  m_x=min_element(a+1,a+n+1,cmp_x)->x;
  m_y=min_element(a+1,a+n+1,cmp_y)->y;
  for (int i=1;i<=n;++i){
    a[i].x-=m_x;
    a[i].y-=m_y;
  }
  m_x=max_element(a+1,a+n+1,cmp_x)->x;
  m_y=max_element(a+1,a+n+1,cmp_y)->y;
  ans=1LL*m_x*m_y;
}

struct case_0{
  
  int suf_min[N+9],suf_max[N+9];
  
  void Get_ans(){
    sort(a+1,a+n+1,cmp_x);
    suf_min[n+1]=inf;suf_max[n+1]=0;
    for (int i=n;i>=1;--i){
      suf_min[i]=min(suf_min[i+1],a[i].y);
      suf_max[i]=max(suf_max[i+1],a[i].y);
    }
    int pre_min=inf,pre_max=0;
    for (int i=1;i<n;++i){
      pre_min=min(pre_min,a[i].y);
      pre_max=max(pre_max,a[i].y);
      ans=min(ans,1LL*(pre_max-pre_min)*a[i].x
        +1LL*(suf_max[i+1]-suf_min[i+1])*(m_x-a[i+1].x));
    }
  }
  
  void operator () (){
    for (int i=1;i<=n;++i) swap(a[i].x,a[i].y);
    swap(m_x,m_y);
    Get_ans();
    for (int i=1;i<=n;++i) swap(a[i].x,a[i].y);
    swap(m_x,m_y);
    Get_ans();
  }
  
}Get_ans0;

struct case_1{
  
  int pre_max[N+9],pre_min[N+9];
  int suf_max[N+9],suf_min[N+9];
  
  void Get_pre_suf(){
    pre_min[0]=inf;pre_max[0]=0;
    for (int i=1;i<=n;++i){
      pre_min[i]=min(pre_min[i-1],a[i].y);
      pre_max[i]=max(pre_max[i-1],a[i].y);
    }
    suf_min[n+1]=inf;suf_max[n+1]=0;
    for (int i=n;i>=1;--i){
      suf_min[i]=min(suf_min[i+1],a[i].y);
      suf_max[i]=max(suf_max[i+1],a[i].y);
    }
  }
  
  int64 tr[N*4+9][4];
  
  void Build(int l,int r,int k){
    if (l==r){
      tr[k][0]=-1LL*a[l].x*m_y;
      tr[k][1]=-1LL*a[l].x*m_y-1LL*pre_min[l-1]*m_x;
      tr[k][2]=-1LL*a[l].x*m_y+1LL*pre_max[l-1]*m_x;
      tr[k][3]=-1LL*a[l].x*m_y+1LL*(pre_max[l-1]-pre_min[l-1])*m_x;
      return;
    }
    int mid=l+r>>1;
    Build(l,mid,k<<1);
    Build(mid+1,r,k<<1|1);
    for (int i=0;i<4;++i) tr[k][i]=min(tr[k<<1][i],tr[k<<1|1][i]);
  }
  
  int64 Query_min(int L,int R,int id,int l,int r,int k){
    if (L<=l&&R>=r) return tr[k][id];
    int mid=l+r>>1;
    int64 res=INF;
    if (L<=mid) res=min(res,Query_min(L,R,id,l,mid,k<<1));
    if (R>mid) res=min(res,Query_min(L,R,id,mid+1,r,k<<1|1));
    return res;
  }
  
  void operator () (){
    sort(a+1,a+n+1,cmp_x);
    Get_pre_suf();
    if (n==1) return;
    Build(2,n,1);
    for (int i=2;i<n;++i){
      int p_min=lower_bound(pre_min+1,pre_min+n+1
        ,suf_min[i+1],greater<int>())-pre_min+1;
      int p_max=lower_bound(pre_max+1,pre_max+n+1,suf_max[i+1])-pre_max+1;
      p_min=min(p_min,i+1);
      p_max=min(p_max,i+1);
      int64 tmp=1LL*a[i].x*m_y;
      if (min(p_min,p_max)>2)
        ans=min(ans,tmp+1LL*m_x*(suf_max[i+1]-suf_min[i+1])
          +Query_min(2,min(p_min,p_max)-1,0,2,n,1));
      if (p_min<p_max)
        ans=min(ans,tmp+1LL*m_x*suf_max[i+1]
          +Query_min(p_min,p_max-1,1,2,n,1));
      if (p_max<p_min)
        ans=min(ans,tmp-1LL*m_x*suf_min[i+1]
          +Query_min(p_max,p_min-1,2,2,n,1));
      if (max(p_min,p_max)<=i)
        ans=min(ans,tmp+Query_min(max(p_min,p_max),i,3,2,n,1));
    }
  }
  
}Get_ans1;

struct case_2{
  
  int pre[N+9],suf[N+9];
  
  void Get_pre_suf(){
    pre[0]=inf;
    for (int i=1;i<=n;++i) pre[i]=min(pre[i-1],a[i].y);
    suf[n+1]=0;
    for (int i=n;i>=1;--i) suf[i]=max(suf[i+1],a[i].y);
  }
  
  struct line{
    int64 x,y;
    line(int64 X=0,int64 Y=0):x(X),y(Y){}
    int64 operator () (pair<int64,int64>p)const{return x*p.second+y*p.first;}
  };
  
  struct tree{
    
    vector<line>a;
    int pos;
    
    int64 Query_max(pair<int,int>x){
      for (;pos+1<a.size()&&a[pos](x)<a[pos+1](x);++pos);
      return a[pos](x);
    }
    
  }tr[N*4+9];
  
  void Pushup(int k){
    auto &d=tr[k].a;
    d=tr[k<<1].a;
    for (line t:tr[k<<1|1].a){
      if (t.x==d.back().x) continue;
      auto Check=[&](const line &a,const line &b,const line &c){
        return (b.y-c.y)*(b.x-a.x)>(a.y-b.y)*(c.x-b.x);
      };
      for (;d.size()>=2&&!Check(d.end()[-2],d.back(),t);d.pop_back());
      d.push_back(t);
    }
  }
  
  void Build(int l,int r,int k){
    tr[k].pos=0;
    if (l==r){
      tr[k].a=vector<line>(1,line(a[l].x,pre[l-1]));
      //printf("%d %d\n",a[l].x,pre[l-1]);
      return;
    }
    int mid=l+r>>1;
    Build(l,mid,k<<1);
    Build(mid+1,r,k<<1|1);
    Pushup(k);
  }
  
  int64 Query_max(int L,int R,pair<int64,int64>x,int l,int r,int k){
    if (L<=l&&R>=r) return tr[k].Query_max(x);
    int mid=l+r>>1;
    int64 res=-INF;
    if (L<=mid) res=max(res,Query_max(L,R,x,l,mid,k<<1));
    if (R>mid) res=max(res,Query_max(L,R,x,mid+1,r,k<<1|1));
    return res;
  }
  
  void Get_ans(){
    sort(a+1,a+n+1,[&](const point &a,const point &b){
      return a.x<b.x||a.x==b.x&&a.y>b.y;
    });
    Get_pre_suf();
    Build(1,n,1);
    //puts("");
    for (int i=n,j=n;i>=1;--i){
      if (!a[i].x) continue;
      //printf("%d %d\n",a[i].x,suf[i+1]);
      for (;j>=1&&pre[j-1]<=suf[i+1];--j);
      if (j<i)
        ans=min(ans,1LL*a[i].x*m_y+1LL*suf[i+1]*m_x
          -Query_max(j+1,i,pair<int64,int64>(a[i].x,suf[i+1]),1,n,1));
    }
  }
  
  void operator () (){
    Get_ans();
    for (int i=1;i<=n;++i) a[i].y=m_y-a[i].y;
    Get_ans();
  }
  
}Get_ans2;

void Get_ans(){
  Get_ans0();
  Get_ans1();
  Get_ans2();
}

void Out(){ 
  printf("%lld\n",ans);
}

void work(){
  In();
  Get_m();
  Get_ans();
  Out();
}

int main(){
  int T=1;
  scanf("%d",&T);
  for (;T--;) work();
  return 0;
}