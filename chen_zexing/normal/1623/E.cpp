#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;
int label[200005];
char s[200005];
int l[200005],fa[200005],r[200005],nxt[200005],d[200005],f[200005],nowd=-1,k;
int seq[200005],cnt;
void dfs1(int x){
    if(l[x]) fa[l[x]]=x,d[l[x]]=d[x]+1,dfs1(l[x]);
    seq[++cnt]=x;
    if(r[x]) fa[r[x]]=x,d[r[x]]=d[x]+1,dfs1(r[x]);
}
void solve(int x,int av){
    if(x==0) return;
    solve(l[x],av);
    if(nowd>d[x]) nowd=d[x];
    printf("%c",label[x]+'a'-1);
    if(av&&(f[x]||label[x]<label[nxt[x]]&&d[x]-nowd<=k)){
        int td=d[x],xx=x;
        while(td>nowd) f[xx]=1,xx=fa[xx],td--;
        k-=d[x]-nowd,nowd=d[x],printf("%c",label[x]+'a'-1);
    }
    else if(label[x]>label[nxt[x]]) av=0;
    solve(r[x],av);
}
int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        int n;
        cin>>n>>k;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) label[i]=s[i]-'a'+1;
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        dfs1(1);
        for(int i=n;i>=1;i--){
            if(label[seq[i]]!=label[seq[i+1]]) nxt[seq[i]]=seq[i+1];
            else nxt[seq[i]]=nxt[seq[i+1]];
        }
        solve(1,1);
    }
    return 0;
}