/*
 * @Author: BilyHurington
 * @Date: 2020-07-20 23:16:49
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-22 14:35:54
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
char s[500010];string T[50010];
namespace Segment_Tree{
    int Lson[20000010],Rson[20000010],Node_tot;
    pair<int,int> Maxn[20000010];
    pair<int,int> Merge(pair<int,int> p1,pair<int,int> p2){return p1.first==p2.first?min(p1,p2):max(p1,p2);}
    void Modify(int &k,int l,int r,int x,int val){
        if(!k){k=++Node_tot;}
        if(l==r){Maxn[k]=make_pair(Maxn[k].first+val,l);return;}
        int mid=(l+r)>>1;
        if(x<=mid) Modify(Lson[k],l,mid,x,val);
        else Modify(Rson[k],mid+1,r,x,val);
        Maxn[k]=Merge(Maxn[Lson[k]],Maxn[Rson[k]]);
    }
    int Merge(int k1,int k2,int l,int r){
        if(!k1||!k2) return k1|k2;
        int k=++Node_tot;
        if(l==r){Maxn[k]=make_pair(Maxn[k1].first+Maxn[k2].first,l);return k;}
        int mid=(l+r)>>1;
        Lson[k]=Merge(Lson[k1],Lson[k2],l,mid);
        Rson[k]=Merge(Rson[k1],Rson[k2],mid+1,r);
        Maxn[k]=Merge(Maxn[Lson[k]],Maxn[Rson[k]]);
        return k;
    }
    pair<int,int> Query(int k,int l,int r,int x,int y){
        if(!k) return make_pair(0,0);
        if(x<=l&&r<=y) return Maxn[k];
        int mid=(l+r)>>1;
        if(x<=mid&&mid<y) return Merge(Query(Lson[k],l,mid,x,y),Query(Rson[k],mid+1,r,x,y));
        if(x<=mid) return Query(Lson[k],l,mid,x,y);
        return Query(Rson[k],mid+1,r,x,y);
    }
}
namespace Suffix_Automation{
    int ch[500010][26],len[500010],fail[500010],rt[500010],last_node,tot=1;
    void Insert(int x,int bel){
        int now=++tot,p=last_node;
        len[now]=len[last_node]+1;
        last_node=now;
        Segment_Tree::Modify(rt[now],1,m,bel,1);
        // printf("Modify: %d %d\n",now,bel);
        for(;p&&!ch[p][x];p=fail[p]) ch[p][x]=now;
        if(!p){fail[now]=1;return;}
        int noww=ch[p][x];
        if(len[noww]==len[p]+1){fail[now]=noww;return;}
        int clone_noww=++tot;
        memcpy(ch[clone_noww],ch[noww],sizeof(ch[noww]));
        len[clone_noww]=len[p]+1;
        fail[clone_noww]=fail[noww];
        for(;p&&ch[p][x]==noww;p=fail[p]) ch[p][x]=clone_noww;
        fail[now]=fail[noww]=clone_noww;
    }
    int V[500010],V_len[500010],now,now_len;
    void visit(char *s){
        V[0]=now=1;V_len[0]=now_len=0;
        for(int i=1;i<=n;i++){
            while(now>0&&!ch[now][s[i]-'a']) now=fail[now],now_len=len[now];
            if(!now) now=1,now_len=0;
            else now=ch[now][s[i]-'a'],now_len++;
            // printf("%d %d\n",V[i],V_len[i]);
            V[i]=now;V_len[i]=now_len;
        }
    }
}
namespace Tree{
    using namespace Suffix_Automation;
    int F[500010][20];
    vector<int> v[500010];
    void dfs(int x){
        for(int i=0;i<v[x].size();i++){
            F[v[x][i]][0]=x;
            dfs(v[x][i]);
            rt[x]=Segment_Tree::Merge(rt[x],rt[v[x][i]],1,m);
            // printf("Merge: %d %d\n",x,v[x][i]);
        }
    }
    void build_tree(){
        for(int i=2;i<=tot;i++) v[fail[i]].push_back(i);
        dfs(1);
        for(int i=1;i<20;i++){
            for(int j=1;j<=tot;j++){
                F[j][i]=F[F[j][i-1]][i-1];
            }
        }
    }
}
using namespace Tree;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        cin>>T[i];last_node=1;
        for(int j=0,k=T[i].length();j<k;j++){
            Insert(T[i][j]-'a',i);
        }
    }
    build_tree();visit(s);
    int pl,pr,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&l,&r,&pl,&pr);
        if(pr-pl+1>V_len[pr]){printf("%d 0\n",l);continue;}
        int now=V[pr];
        for(int i=19;i>=0;i--) if(pr-pl+1<=len[F[now][i]]) now=F[now][i];
        // printf("%d\n",now);
        pair<int,int> ans=Segment_Tree::Query(rt[now],1,m,l,r);
        if(ans.first==0) printf("%d 0\n",l);
        else printf("%d %d\n",ans.second,ans.first);
    }
    return 0;
}