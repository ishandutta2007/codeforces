/*
 * @Author: BilyHurington
 * @Date: 2020-08-11 15:27:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-11 17:14:00
 */
#include<bits/stdc++.h>
using namespace std;
int n,q;
struct Query{int id,L,K;long long Ans;}Q[1000010];
bool cmp1(const Query &Q1,const Query &Q2){return Q1.L<Q2.L;}
bool cmp2(const Query &Q1,const Query &Q2){return Q1.id==Q2.id?Q1.L<Q2.L:Q1.id<Q2.id;}
namespace BIT{
    long long val[200010];const int N=200005;
    void Modi(int x,int ad){for(;x<=N;x+=(x&-x)) val[x]+=ad;}
    long long Query(long long x){long long ans=0;for(;x;x-=(x&-x)) ans+=val[x];return ans;}
}
string s[200010];
vector<int> T[200010],Pos[200010];
int dfn[200010],dfn_tot,siz[200010];
namespace AC_Automation{
    int ch[200010][26],fail[200010],node_tot;
    void Insert(const string &s,int id){
        int now=0;
        for(int i=0;i<s.length();i++){
            if(!ch[now][s[i]-'a']) ch[now][s[i]-'a']=++node_tot;
            now=ch[now][s[i]-'a'];
            Pos[id].push_back(now);
        }
    }
    void BFS(){
        queue<int> q;
        for(int i=0;i<26;i++) if(ch[0][i]) q.push(ch[0][i]);
        while(q.size()){
            int x=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(!ch[x][i]) ch[x][i]=ch[fail[x]][i];
                else fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
            }
        }
    }
    void Dfs(int x){
        dfn[x]=++dfn_tot;siz[x]=1;
        for(int i=0;i<T[x].size();i++){
            Dfs(T[x][i]);
            siz[x]+=siz[T[x][i]];
        }
    }
    void Build_Tree(){
        for(int i=1;i<=n;i++) Insert(s[i],i);
        BFS();
        for(int i=1;i<=node_tot;i++) T[fail[i]].push_back(i);
        Dfs(0);
    }
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) cin>>s[i];
    AC_Automation::Build_Tree();
    for(int i=1,L,R,K;i<=q;i++){
        scanf("%d %d %d",&L,&R,&K);
        Q[2*i-1]=Query{i,L-1,K,0};
        Q[2*i]=Query{i,R,K,0};
    }
    sort(Q+1,Q+2*q+1,cmp1);
    int now=1;
    while(now<=2*q&&!Q[now].L) Q[now].Ans=0,now++;
    for(int i=1;i<=n;i++){
        for(int j=0;j<Pos[i].size();j++) BIT::Modi(dfn[Pos[i][j]],1);
        while(now<=2*q&&Q[now].L<=i){
            int id=Pos[Q[now].K].back();
            Q[now].Ans=BIT::Query(dfn[id]+siz[id]-1)-BIT::Query(dfn[id]-1);
            now++;
        }
    }
    sort(Q+1,Q+2*q+1,cmp2);
    for(int i=1;i<=q;i++) printf("%lld\n",Q[2*i].Ans-Q[2*i-1].Ans);
    return 0;
}