#include<iostream>
#include<cstring>
#include<vector>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,b,a) for(int i=(b);i>=(a);i--)
#define N 110
using namespace std;
int head[N],to[2*N],nxt[2*N];
int cnt,n,k;
int len[N],now,Left,big[N];
bool lian[N];
vector<int> ans;
void init(){
    mem(head,-1),cnt=-1,mem(lian,false);
    ans.clear();
}
void add_e(int a,int b,bool id){
    nxt[++cnt]=head[a],head[a]=cnt,to[cnt]=b;
    if(id)add_e(b,a,0);
}
bool Max(int &a,int b){return a<b?a=b,1:0;}
void dfs(int x,int fa){
    int mx=0,node=-1;
    for(int i=head[x];~i;i=nxt[i]){
        if(to[i]==fa)continue;
        dfs(to[i],x);
        if(Max(mx,len[to[i]]))node=to[i];
    }
    big[x]=node;
    len[x]=mx+1;
}
void addtag(int x){
    if(x==-1)return;
    lian[x]=true;
    addtag(big[x]);
}
void solve(int x,int fa){
    ans.push_back(x),now++;
    if(!lian[x])Left--;
    //cout<<x<<' '<<fa<<" "<<now<<" "<<Left<<endl;
    if((!lian[x]&&Left==0)||now>=k)return;
    for(int i=head[x];~i;i=nxt[i]){
        if(Left==0)break;
        if(to[i]==fa||lian[to[i]])continue;
        solve(to[i],x);
        ans.push_back(x);
    }
    for(int i=head[x];~i;i=nxt[i])
        if(lian[to[i]]&&to[i]!=fa){
            solve(to[i],x);
            break;
        }
}
int main(){
    ios::sync_with_stdio(false);
    int T,f;
    cin>>T;
    while(T--){
        cin>>n>>k;
        init();
        rep(i,2,n)cin>>f,add_e(i,f,1);
        dfs(1,0);
        addtag(1);
        lian[1]=true;
        //rep(i,1,n)cout<<i<<":"<<len[i]<<" "<<lian[i]<<endl;
        now=0,Left=max(0,k-len[1]);
        solve(1,0);
        cout<<(int)ans.size()-1<<endl;
        rep(i,0,(int)ans.size()-1)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}