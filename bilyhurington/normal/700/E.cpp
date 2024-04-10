#include<bits/stdc++.h>
using namespace std;
int n;char s[200010];
namespace Segment_Tree{
    struct Node{int ls,rs;}N[10000010];
    int seg_tot;
    void Modify(int &k,int l,int r,int x){
        if(!k) k=++seg_tot;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(x<=mid) Modify(N[k].ls,l,mid,x);
        else Modify(N[k].rs,mid+1,r,x);
    }
    bool Query(int k,int l,int r,int x,int y){
        if(!k) return 0;
        if(x<=l&&r<=y) return 1;
        int mid=(l+r)>>1;
        if(x<=mid&&Query(N[k].ls,l,mid,x,y)) return 1;
        if(mid<y&&Query(N[k].rs,mid+1,r,x,y)) return 1;
        return 0;
    }
    int Merge(int rt1,int rt2){
        if(!rt1||!rt2) return rt1|rt2;
        int k=++seg_tot;
        N[k].ls=Merge(N[rt1].ls,N[rt2].ls);
        N[k].rs=Merge(N[rt1].rs,N[rt2].rs);
        return k;
    }
}
using namespace Segment_Tree;
int rt[400010],pos[400010];
namespace Suffix_Automation{
    int ch[400010][26],fail[400010],len[400010],node_tot,last_node;
    void Init(){node_tot=last_node=1;}
    void Insert(int c,int ps){
        int now=++node_tot,p=last_node;
        len[now]=len[last_node]+1;
        pos[now]=ps;
        Modify(rt[now],1,n,ps);
        last_node=now;
        for(;p&&!ch[p][c];p=fail[p]) ch[p][c]=now;
        if(!p){fail[now]=1;return;}
        int noww=ch[p][c];
        if(len[noww]==len[p]+1){fail[now]=noww;return;}
        int clone_noww=++node_tot;
        pos[clone_noww]=pos[noww];
        fail[clone_noww]=fail[noww];
        memcpy(ch[clone_noww],ch[noww],sizeof(ch[noww]));
        len[clone_noww]=len[p]+1;
        for(;p&&ch[p][c]==noww;p=fail[p]) ch[p][c]=clone_noww;
        fail[now]=fail[noww]=clone_noww;
    }
}
using namespace Suffix_Automation;
vector<int> T[400010];
void dfs_sam(int x){
    for(int i=0;i<T[x].size();i++){
        dfs_sam(T[x][i]);
        rt[x]=Merge(rt[x],rt[T[x][i]]);
    }
}
int f[400010],rot[400010];
void dfs_solve(int x){
    if(fail[x]==1) f[x]=1,rot[x]=x;
    else{
        if(Query(rt[rot[fail[x]]],1,n,pos[x]-len[x]+len[rot[fail[x]]],pos[x]-1)) f[x]=f[fail[x]]+1,rot[x]=x;
        else f[x]=f[fail[x]],rot[x]=rot[fail[x]];
    }
    for(int i=0;i<T[x].size();i++) dfs_solve(T[x][i]);
}
int main(){
    scanf("%d %s",&n,s+1);Init();
    for(int i=1;i<=n;i++) Insert(s[i]-'a',i);
    for(int i=2;i<=node_tot;i++) T[fail[i]].push_back(i);
    dfs_sam(1);
    for(int i=0;i<T[1].size();i++) dfs_solve(T[1][i]);
    int ans=0;
    for(int i=1;i<=node_tot;i++) ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}