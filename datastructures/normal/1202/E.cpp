#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
struct accept{
    int son[26],fail,cnt;
}a1[200005],a2[200005];
int cnt1,cnt2,n;
char s[200005],x[200005];
inline void build(){
    scanf("%s",x+1);
    int len=strlen(x+1),now;
    now=0;
    for (int i=1;i<=len;i++){
        if (a1[now].son[x[i]-'a']==0)a1[now].son[x[i]-'a']=++cnt1;
        now=a1[now].son[x[i]-'a'];
        if (i==len)a1[now].cnt++;
    }
    now=0;
    for (int i=len;i>=1;i--){
        if (a2[now].son[x[i]-'a']==0)a2[now].son[x[i]-'a']=++cnt2;
        now=a2[now].son[x[i]-'a'];
        if (i==1)a2[now].cnt++;
    }
    return;
}
int head,tail,q[200005];
inline void getfail(){
    head=1,tail=0;
    for (int i=0;i<26;i++)
        if (a1[0].son[i]!=0)q[++tail]=a1[0].son[i];
    while(head<=tail){
        int now=q[head];
        head++;
        for (int i=0;i<26;i++){
            if (a1[now].son[i]!=0){
                a1[a1[now].son[i]].fail=a1[a1[now].fail].son[i];
                q[++tail]=a1[now].son[i];
            }
            else a1[now].son[i]=a1[a1[now].fail].son[i];
        }
    }
    head=1,tail=0;
    for (int i=0;i<26;i++)
        if (a2[0].son[i]!=0)q[++tail]=a2[0].son[i];
    while(head<=tail){
        int now=q[head];
        head++;
        for (int i=0;i<26;i++){
            if (a2[now].son[i]!=0){
                a2[a2[now].son[i]].fail=a2[a2[now].fail].son[i];
                q[++tail]=a2[now].son[i];
            }
            else a2[now].son[i]=a2[a2[now].fail].son[i];
        }
    }
    return;
}
int u[200005],v[200005],first[200005],nxt[200005];
inline void dfs1(int now){
    for (int i=first[now];i;i=nxt[i]){
        a1[v[i]].cnt+=a1[now].cnt;
        dfs1(v[i]);
    }
    return;
}
inline void dfs2(int now){
    for (int i=first[now];i;i=nxt[i]){
        a2[v[i]].cnt+=a2[now].cnt;
        dfs2(v[i]);
    }
    return;
}
inline void upcnt(){
    memset(first,0,sizeof(first));
    memset(nxt,0,sizeof(nxt));
    for (int i=1;i<=cnt1;i++){
        u[i]=a1[i].fail,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    dfs1(0);
    memset(first,0,sizeof(first));
    memset(nxt,0,sizeof(nxt));
    for (int i=1;i<=cnt2;i++){
        u[i]=a2[i].fail,v[i]=i;
        nxt[i]=first[u[i]],first[u[i]]=i;
    }
    dfs2(0);
    return;
}
int l[200005],r[200005];
int ans;
inline void calc(){
    int len=strlen(s+1),now;
    now=0;
    for (int i=1;i<=len;i++){
        now=a1[now].son[s[i]-'a'];
        l[i]+=a1[now].cnt;
    }
    now=0;
    for (int i=len;i>=1;i--){
        now=a2[now].son[s[i]-'a'];
        r[i]+=a2[now].cnt;
    }
    for (int i=1;i<len;i++)ans+=l[i]*r[i+1];
    return;
}
signed main(){
    scanf("%s",s+1);
    cin>>n;
    for (int i=1;i<=n;i++)build();
    getfail();
    upcnt();
    calc();
    cout<<ans<<endl;
}