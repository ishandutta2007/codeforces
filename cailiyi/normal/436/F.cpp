#include<bits/stdc++.h>
#define N 100000
#define B 320
#define pil pair<int,long long>
using namespace std;
int n,w,tag[N/B+5],st[N/B+5][B+5],pos[N/B+5];
pair<int,int> a[N+B];
pil node[N+B];
inline int belong(int i) {return (i-1)/B+1;}
inline pil operator-(const pil &a,const pil &b) {return {a.first-b.first,a.second-b.second};}
inline long long operator*(const pil &a,const pil &b) {return 1ll*a.first*b.second-1ll*a.second*b.first;}
inline long long calc(const pil &x,const int &k) {return x.second+1ll*x.first*k;}
inline void build(int i)
{
    st[i][0]=0;for(int j=(i-1)*B+1;j<=i*B;st[i][++st[i][0]]=j++)
        while(st[i][0]>1 && ((node[j]-node[st[i][st[i][0]]])*(node[j]-node[st[i][st[i][0]-1]]))<0) --st[i][0];
    for(pos[i]=1;pos[i]<st[i][0] && calc(node[st[i][pos[i]+1]],tag[i])>calc(node[st[i][pos[i]]],tag[i]);++pos[i]);
}
inline void add(int x)
{
    int i=1;for(i=1;i*B<=x;++i)
        for(++tag[i];pos[i]<st[i][0] && calc(node[st[i][pos[i]+1]],tag[i])>calc(node[st[i][pos[i]]],tag[i]);++pos[i]);
    if(x==(i-1)*B) return;
    for(int j=i*B;j>(i-1)*B;--j)
        node[j].second+=1ll*(tag[i]+(j<=x))*j;
    tag[i]=0,build(belong(x));
}
inline pair<long long,int> query()
{
    pair<long long,int> ret={0,0};for(int i=belong(N);i;--i)
        ret=max(ret,{calc(node[st[i][pos[i]]],tag[i]),st[i][pos[i]]});
    return ret;
}
int main()
{
    scanf("%d %d",&n,&w);
    for(int i=1;i<=n;++i) scanf("%d %d",&a[i].second,&a[i].first);
    for(int i=belong(N)*B;i;--i) node[i].first=i;
    for(int i=belong(N);i;--i) build(i);
    sort(a+1,a+1+n),puts("0 1");
    for(int i=1,j=1;i<=a[n].first+1;++i)
    {
        for(;j<=n && a[j].first<i;++j) add(a[j].second);
        pair<long long,int> ans=query();
        printf("%lld %d\n",ans.first+1ll*w*i*(n-j+1),ans.second);
    }
    return 0;
}