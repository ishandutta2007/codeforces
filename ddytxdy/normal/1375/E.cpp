#include<bits/stdc++.h>
#define LL long long
#define pii pair<LL,LL>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1010;
int n,a[N],p[N],c[N],cnt[N],pre[N],nxt[N],H,num;
void insert(int x){
    nxt[x]=nxt[H];pre[nxt[H]]=x;pre[x]=H;nxt[H]=x;
}
void erase(int x){
    pre[nxt[x]]=pre[x];nxt[pre[x]]=nxt[x];pre[x]=nxt[x]=0;
}
bool ck(int x){return p[x+1]<p[x];}
int main(){
    scanf("%d",&n);H=n+1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i];
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        int v=lower_bound(c+1,c+n+1,a[i])-c;
        a[i]=v+cnt[v];cnt[v]++;
    }
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i]>a[j])num++;
    printf("%d\n",num);
    for(int i=1;i<=n;i++)p[a[i]]=i;
    for(int i=1;i<n;i++)if(p[i+1]<p[i])insert(i);
    while(nxt[H]){
        int x=nxt[H],u=p[x],v=p[x+1];if(u>v)swap(u,v);
        printf("%d %d\n",u,v);
        swap(a[p[x]],a[p[x+1]]);swap(p[x],p[x+1]);
        erase(x);
        if(x>1&&pre[x-1]&&!ck(x-1))erase(x-1);
        if(x>1&&!pre[x-1]&&ck(x-1))insert(x-1);
        if(x+1<n&&pre[x+1]&&!ck(x+1))erase(x+1);
        if(x+1<n&&!pre[x+1]&&ck(x+1))insert(x+1);
    }
    return 0;
}