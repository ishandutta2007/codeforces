#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e6+50;
int n,m,q,x,ver[N],nxt[N],head[N],tot,in[N],out[N],st[N],tp;LL lst[N],ans;
int New(){
    if(tp)return st[tp--];
    return ++tot;
}
void add(int x,int y){int id=New();ver[id]=y;nxt[id]=head[x];head[x]=id;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        add(x,y);in[y]++;out[x]++;
    }
    for(int i=1;i<=n;i++)ans+=lst[i]=1ll*in[i]*out[i];
    printf("%I64d\n",ans);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        in[x]+=out[x];out[x]=0;ans-=lst[x];lst[x]=0;
        for(int i=head[x],y;i;i=nxt[i]){
            in[y=ver[i]]--;out[y]++;add(y,x);
            ans-=lst[y];ans+=lst[y]=1ll*in[y]*out[y];
        }
        for(int i=head[x];i;i=nxt[i])st[++tp]=i;
        head[x]=0;printf("%I64d\n",ans);
    }
    return 0;
}