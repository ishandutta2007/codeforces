#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct accept{
    int son[26],fail;
    accept(){
        memset(son,0,sizeof(son));
        fail=0;
    }
}a[400005];
struct TRIE{
    int son[26];
    TRIE(){
        memset(son,0,sizeof(son));
    }
}trie[400005];
int cnt1,cnt2,end1[400005],end2[400005],n,m;
char s[400005];
vector <int>id[400005];
vector <int>c[400005];
inline int build(){
    int len=strlen(s+1),now=0;
    for (int i=1;i<=len;i++){
        if (a[now].son[s[i]-'a']==0)a[now].son[s[i]-'a']=++cnt2;
        now=a[now].son[s[i]-'a'];
        if (i==len)return now;
    }
    return 0;
}
int head=1,tail,q[400005];
inline void getfail(){
    for (int i=0;i<26;i++)  
        if (a[0].son[i]!=0)q[++tail]=a[0].son[i];
    while(head<=tail){
        int now=q[head];
        head++;
        for (int i=0;i<26;i++){
            if (a[now].son[i]!=0){
                a[a[now].son[i]].fail=a[a[now].fail].son[i];
                q[++tail]=a[now].son[i];
            }
            else a[now].son[i]=a[a[now].fail].son[i];
        }
    }
    return;
}
int u[400005],v[400005],first[400005],nxt[400005];
int nowtime,times[400005],l[400005],r[400005];
inline void gettimes(int now){
    ++nowtime;
    l[now]=times[now]=nowtime;
    for (int i=first[now];i;i=nxt[i])
        gettimes(v[i]);
    r[now]=nowtime;
    return;
}
struct BIT{
    int tree[1000005];
    BIT(){
        memset(tree,0,sizeof(tree));
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void add(int pos,int val){
        while(pos<=1000000)tree[pos]+=val,pos+=lowbit(pos);
        return;
    }
    inline int query(int pos){
        int ans=0;
        while(pos)ans+=tree[pos],pos-=lowbit(pos);
        return ans;
    }
}bit;
inline void add(int x){
    bit.add(times[x],1);
    return;
}
inline void del(int x){
    bit.add(times[x],-1);
    return;
}
inline int ask(int x){
    return bit.query(r[x])-bit.query(l[x]-1);
}
int ans[400005];
inline void dfs(int now1,int now2){
    add(now2);
    for (int i=0,len=c[now1].size();i<len;i++)
        ans[id[now1][i]]=ask(c[now1][i]);
    for (int i=0;i<26;i++)
        if (trie[now1].son[i]!=0)dfs(trie[now1].son[i],a[now2].son[i]);
    del(now2);
    return;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        int opt;
        scanf("%d",&opt);
        if (opt==1){
            scanf("%s",s+1);
            if (trie[0].son[s[1]-'a']==0)trie[0].son[s[1]-'a']=++cnt1;
            end1[i]=trie[0].son[s[1]-'a'];
        }
        else{
            int pre;
            scanf("%d%s",&pre,s+1);
            pre=end1[pre];
            if (trie[pre].son[s[1]-'a']==0)trie[pre].son[s[1]-'a']=++cnt1;
            end1[i]=trie[pre].son[s[1]-'a'];
        }
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        int x;
        scanf("%d%s",&x,s+1);
        end2[i]=build();
        c[end1[x]].push_back(end2[i]);
        id[end1[x]].push_back(i);
    }
    getfail();
    for (int i=1;i<=cnt2;i++){
        u[i]=a[i].fail,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    gettimes(0);
    dfs(0,0);
    for (int i=1;i<=m;i++)printf("%d\n",ans[i]);
}