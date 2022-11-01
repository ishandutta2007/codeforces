#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000005
#define inf 1000000001
#define mid ((l+r)>>1)
int n,x[N],y[N],tot,q[N],key[N<<2];
long long ans,sum[N<<2];
using namespace std;
struct line{
    int x,y1,y2,flag;
}l[N];
template<class T>inline void rread(T&num){
    num=0;T f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    num*=f;
}
inline bool cmp(line a,line b){
    return a.x<b.x;
}
inline int find(int x){
    int l=1,r=tot;
    while(l<=r){
        if(q[mid]==x)return mid;
        if(q[mid]>x)r=mid-1;
        else l=mid+1;
    }
}
inline void pushup(int x,int l,int r){
    if(key[x]>0)sum[x]=q[r]-q[l];
    else if(r==l+1)sum[x]=0;
    else sum[x]=sum[x<<1]+sum[x<<1|1];
}
inline void insert(int x,int l,int r,int ll,int rr,int num){
    if(ll==rr)return;
    if(l==ll&&r==rr){
        key[x]+=num;
        pushup(x,l,r);
        return;
    }
    if(rr<=mid)insert(x<<1,l,mid,ll,rr,num);
    else if(ll>mid)insert(x<<1|1,mid,r,ll,rr,num);
    else insert(x<<1,l,mid,ll,mid,num),insert(x<<1|1,mid,r,mid,rr,num);
    pushup(x,l,r);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    rread(n);
    for(int i=1;i<=n;i++){
        rread(l[2*i-1].x);rread(l[2*i-1].y1);rread(l[2*i].x);rread(l[2*i].y2);
		if(l[2*i-1].x>l[2*i].x)swap(l[2*i-1].x,l[2*i].x),swap(l[2*i-1].y1,l[2*i].y2);
		if(l[2*i-1].y1>l[2*i].y2)swap(l[2*i-1].x,l[2*i].x),swap(l[2*i-1].y1,l[2*i].y2);
		l[2*i-1].x--;l[2*i-1].y1--;
        l[2*i-1].y2=l[2*i].y2;l[2*i].y1=l[2*i-1].y1;
        l[2*i-1].flag=1;l[2*i].flag=-1;
        q[2*i-1]=l[2*i-1].y1;q[2*i]=l[2*i].y2;
    }
    tot=2*n;
    sort(q+1,q+2*n+1);
    for(int i=2;i<=2*n;i++)if(q[i]==q[i-1])q[i-1]=inf,tot--;
    sort(q+1,q+2*n+1);
    sort(l+1,l+2*n+1,cmp);
    insert(1,1,tot+1,find(l[1].y1),find(l[1].y2),l[1].flag);
    for(int i=2;i<=2*n;i++){
        ans+=sum[1]*(l[i].x-l[i-1].x);
        insert(1,1,tot+1,find(l[i].y1),find(l[i].y2),l[i].flag);
    }
    printf("%lld\n",ans);
    return 0;
}