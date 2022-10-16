#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define maxn 2000000
using namespace std;
int n,T,_end[2000005],num[2000005];
char s[2000005];
struct accept{
    int son[26],fail,val;
    accept(){
        memset(son,0,sizeof(son));
        fail=val=0;
    }
}a[1200005];
int cnt;
inline void build(int x){
    scanf("%s",s+1);
    int len=strlen(s+1),now=0;
    for (int i=1;i<=len;i++){
        if (a[now].son[s[i]-'a']==0)a[now].son[s[i]-'a']=++cnt;
        now=a[now].son[s[i]-'a'];
        if (i==len)_end[x]=now;
    }
    return;
}
int head,tail,q[2000005];
inline void getfail(){
    head=1,tail=0;
    for (int i=0;i<26;i++)
        if (a[0].son[i]!=0)q[++tail]=a[0].son[i];
    while(head<=tail){
        int now=q[head];
        ++head;
        for (int j=0;j<26;j++){
            if (a[now].son[j]!=0){
                a[a[now].son[j]].fail=a[a[now].fail].son[j];
                q[++tail]=a[now].son[j];
            }   
            else a[now].son[j]=a[a[now].fail].son[j];
        }
    }
    return;
}
struct BIT{
    int tree[2000005];
    inline void mem(){
        memset(tree,0,sizeof(tree));
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    inline int query(int pos){
        int ans=0;
        while(pos)ans+=tree[pos],pos-=lowbit(pos);
        return ans;
    }
    inline void tree_add(int pos,int val){
        while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
    }
    inline void add(int l,int r,int k){
        tree_add(l,k);
        tree_add(r+1,-k);
    }
}bit;
int u[2000005],v[2000005],first[2000005],nxt[2000005];
int l[2000005],r[2000005],times[2000005],nowtime;
inline void gettimes(int now){
    ++nowtime;
    times[now]=l[now]=nowtime;
    for (int i=first[now];i;i=nxt[i])
        gettimes(v[i]);
    r[now]=nowtime;
    return;
}
inline void add(int x){
    bit.add(l[x],r[x],1);
    return;
}
inline void del(int x){
    bit.add(l[x],r[x],-1);
    return;
}
int main(){
    cin>>T>>n;
    for (int i=1;i<=n;i++)
        build(i);
    getfail();
    for (int i=1;i<=cnt;i++){
        u[i]=a[i].fail,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    gettimes(0);
    bit.mem();
    for (int i=1;i<=n;i++)add(_end[i]),num[i]=1;
    while(T--){
        char opt;
        cin>>opt;
        if (opt=='+'){
            int x;
            scanf("%d",&x);
            if (num[x]==0)add(_end[x]);
            num[x]=1;
        }
        else if (opt=='-'){
            int x;
            scanf("%d",&x);
            if (num[x]==1)del(_end[x]);
            num[x]=0;
        }
        else{
            scanf("%s",s+1);
            int len=strlen(s+1);
            int now=0,ans=0;
            for (int i=1;i<=len;i++){
                now=a[now].son[s[i]-'a'];
                if (now!=0)ans+=bit.query(times[now]);
            }
            printf("%d\n",ans);
        }
    }
}