#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,q,opt,l,r,cnt[26];
char s[100005];
struct SGT{
    int tree[400005],tag[400005];
    SGT(){
        memset(tree,0,sizeof(tree));
        memset(tag,-1,sizeof(tag));
        return;
    }
    inline void pushdown(int now,int nowl,int nowr){
        int mid=(nowl+nowr)/2;
        if (tag[now]==0){
            tag[now*2]=tag[now*2+1]=0;
            tree[now*2]=tree[now*2+1]=0;
        }
        if (tag[now]==1){
            tag[now*2]=tag[now*2+1]=1;
            tree[now*2]=mid-nowl+1;
            tree[now*2+1]=nowr-mid;
        }
        tag[now]=-1;
        return;
    }
    inline void pushup(int now){
        tree[now]=tree[now*2]+tree[now*2+1];
        return;
    }
    inline void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
        if (nowl!=nowr)pushdown(now,nowl,nowr);
        if (nowl>=lt&&nowr<=rt){
            if (val==0){
                tree[now]=0;
                tag[now]=0;
            }
            else{
                tree[now]=nowr-nowl+1;
                tag[now]=1;
            }
            return;
        }
        int mid=(nowl+nowr)/2;
        if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
        if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
        if (nowl!=nowr)pushup(now);
        return;
    }
    inline int tree_query(int now,int nowl,int nowr,int lt,int rt){
        if (nowl!=nowr)pushdown(now,nowl,nowr);
        if (nowl>=lt&&nowr<=rt)return tree[now];
        int mid=(nowl+nowr)/2,s=0;
        if (mid>=lt)s+=tree_query(now*2,nowl,mid,lt,rt);
        if (mid+1<=rt)s+=tree_query(now*2+1,mid+1,nowr,lt,rt);
        return s;
    } 
    inline void update(int nowl,int nowr,int val){
        tree_update(1,1,n,nowl,nowr,val);
        return;
    }
    inline int ask(int nowl,int nowr){
        return tree_query(1,1,n,nowl,nowr);
    }
}sgt[26];
int main(){
    cin>>n>>q;
    scanf("%s",s+1);
    for (int i=1;i<=n;i++)sgt[s[i]-'a'].update(i,i,1);
    while(q--){
        scanf("%d%d%d",&l,&r,&opt);
        if (opt==1){
            int now=l-1;
            for (int i=0;i<26;i++)cnt[i]=sgt[i].ask(l,r),sgt[i].update(l,r,0);
            for (int i=0;i<26;i++){
                if (cnt[i]==0)continue;
                sgt[i].update(now+1,now+cnt[i],1);
                now+=cnt[i];
            }
        }
        else{
            int now=l-1;
            for (int i=0;i<26;i++)cnt[i]=sgt[i].ask(l,r),sgt[i].update(l,r,0);
            for (int i=25;i>=0;i--){
                if (cnt[i]==0)continue;
                sgt[i].update(now+1,now+cnt[i],1);
                now+=cnt[i];
            }
        }
    }
    for (int i=1;i<=n;i++){
        int j;
        for (j=0;j<26;j++)
            if (sgt[j].ask(i,i)==1)break;
        cout<<(char)(j+'a');
    }
    cout<<endl;
    return 0;
}