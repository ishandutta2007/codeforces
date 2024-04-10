#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int ch[maxn][26],cnt=0; 
int pos[maxn],st[maxn]; 
int Laxt[maxn],Next[maxn],To[maxn],tot;
int q[maxn],fail[maxn],head,tail;
int in[maxn],out[maxn],sum[maxn],times;
char c[maxn];
char getopt() { char c=getchar(); while(c!='+'&&c!='-'&&c!='?') c=getchar(); return c;}
void addedge(int u,int v){ Next[++tot]=Laxt[u]; Laxt[u]=tot; To[tot]=v; }
int insert(){
    int L=strlen(c+1),Now=0;
    for(int i=1;i<=L;i++){
        if(!ch[Now][c[i]-'a']) ch[Now][c[i]-'a']=++cnt;
        Now=ch[Now][c[i]-'a'];
    }   return Now;
}
void buildfail(){
    for(int i=0;i<26;i++){
        if(ch[0][i]) q[++head]=ch[0][i],fail[ch[0][i]]=0;
        else ch[0][i]=0;
    }
    while(tail<head){
        int Now=q[++tail];
        for(int i=0;i<26;i++){
            if(ch[Now][i]) {
                q[++head]=ch[Now][i]; fail[ch[Now][i]]=ch[fail[Now]][i];
            }
            else ch[Now][i]=ch[fail[Now]][i];
        }
    }
    for(int i=1;i<=cnt;i++) addedge(fail[i],i);
}
void dfs(int u){
    in[u]=++times;
    for(int i=Laxt[u];i;i=Next[i]) dfs(To[i]);
    out[u]=times;
}
void addsum(int x,int val){ while(x<=times){ sum[x]+=val; x+=(-x)&x;}}
int query(int x){ int res=0;while(x){res+=sum[x];x-=(-x)&x;}return res;}
void solve(){
    int L=strlen(c+1),Now=0,ans=0;
    for(int i=1;i<=L;i++){
        Now=ch[Now][c[i]-'a'];
        ans+=query(in[Now]);    
    }
    printf("%d\n",ans);
}
int main(){
    int N,M,x,i,j;
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++){
        st[i]=1;
        scanf("%s",c+1);
        pos[i]=insert();
    }
    buildfail();
    dfs(0);
    for(i=1;i<=M;i++){
        addsum(in[pos[i]],1);
        addsum(out[pos[i]]+1,-1);
    }
    for(i=1;i<=N;i++){
        char opt=getopt();
        if(opt=='?'){
           scanf("%s",c+1);
           solve();
        }
        else{
            scanf("%d",&x);
            if(opt=='+'){
                if(st[x]==1) continue;st[x]=1;
                addsum(in[pos[x]],1);
                addsum(out[pos[x]]+1,-1);    
            }
            else {
                if(st[x]==0) continue; st[x]=0;
                addsum(in[pos[x]],-1);
                addsum(out[pos[x]]+1,1);
            }
        }
    }
    return 0;
}