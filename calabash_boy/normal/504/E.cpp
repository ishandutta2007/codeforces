// Created by calabash_boy on 18-6-1.
// CF 1003F
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 6e5+100;
const int HASH_CNT = 1;
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={998244353,1000000009,4294967291ull};
struct Hash_1D{
    ULL Seed,Mod;
    ULL bas[maxn];
    ULL sum[maxn];
    void init(int seedIndex,int modIndex,char *s,int n){
        Seed = Seed_Pool[seedIndex];
        Mod = Mod_Pool[modIndex];
        bas[0]=1;
        for (int i=1;i<=n;i++){
            bas[i] = bas[i-1]*Seed%Mod;
        }
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+s[i])%Mod;
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hasher[HASH_CNT];
char s[maxn];
char S[maxn];
int n;
namespace Heavy_Light_Decomposition{
    int first[maxn*2];int nxt[maxn*2];int des[maxn*2];
    int tot,cnt=0;
    int tpos[maxn];int dep[maxn];int top[maxn];
    int fa[maxn]; int wson[maxn];  int sz[maxn];
    inline void addEdge(int _u, int _v){
        des[++tot] = _v;
        nxt[tot] = first[_u];
        first[_u] = tot;
    }
    //depszwson
    void dfs(int node,int father){
        dep[node] = dep[father]+1;
        fa[node] = father;  sz[node] =1;
        for (int t = first[node];t;t = nxt[t]){
            int v = des[t];
            if (v==father){  continue;  }
            dfs(v,node);
            if (sz[v]>sz[wson[node]]){
                wson[node] = v;
            }
            sz[node]+=sz[v];
        }
    }
    //nodechain
    void dfs2(int node,int father,int chain){
        //printf("chain = %d\n",chain);
        top[node] = chain;  tpos[node] = ++cnt;
        S[tpos[node]] = s[node];
        S[n + n + 1 - tpos[node]] = s[node];
        if (wson[node]){
            dfs2(wson[node],node,chain);
        }
        for (int t = first[node];t;t = nxt[t]){
            int v = des[t];
            if (v==father||v ==wson[node]){  continue;  }
            dfs2(v,node,v);
        }
    }
    /* s  */
    void init(int root){
        dfs(root,0);
        dfs2(root, 0, root);
        //puts(S+1);
        //for (int i=1;i<=n;i++){
        //    printf("tpos[%d]=%d\n",i,tpos[i]);
        //}
    }
    vector<pair<int,int> > lca(int x,int y){
        vector<pair<int,int> > vx,vy(0);
        while (top[x]!=top[y]){
            if (dep[top[x]] < dep[top[y]]){
                //jump y
                vy.emplace_back(tpos[top[y]],tpos[y]);
                y = fa[top[y]];
            }else{
                //jump x
                vx.emplace_back(n + n + 1 - tpos[x],n + n + 1 - tpos[top[x]]);
                x = fa[top[x]];
            }
        }
        if (dep[x] < dep[y]){
            //jump y
            vy.emplace_back(tpos[x],tpos[y]);
        }else{
            //jump x
            vx.emplace_back(n + n + 1 - tpos[x],n + n + 1 - tpos[y]);
        }
        reverse(vy.begin(),vy.end());
        vx.insert(vx.end(),vy.begin(),vy.end());
        return vx;
    }
}
void debug(int a,int b,vector<pair<int,int> > v){
    printf("a = %d , b = %d\n",a,b);
    for (pair<int,int> pr : v){
        printf("[%d,%d] ",pr.first,pr.second);
    }
    puts("");
}
bool check(int st1,int st2,int len){
    for (int i=0;i<HASH_CNT;i++){
        ULL hash1 = hasher[i].getHash(st1,st1 + len - 1);
        ULL hash2 = hasher[i].getHash(st2,st2 + len - 1);
        if (hash1 != hash2)return false;
    }
    return true;
}
int work(vector<pair<int,int> > &v1,vector<pair<int,int> > &v2){
    int l1,l2,r1,r2;
    tie(l1,r1) = v1[0];
    tie(l2,r2) = v2[0];
    int len = 0;
    for (int i=0,j=0;i<v1.size() && j < v2.size();){
        pair<int,int> seg1 = v1[i],seg2 = v2[j];
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        int len_to_check = min(len1,len2);
        if (check(l1,l2,len_to_check)){
            l1 += len_to_check;
            l2 += len_to_check;
            len += len_to_check;
            if (l1 == r1 + 1){
                i ++;
                if (i <v1.size()){
                    tie(l1,r1) = v1[i];
                }
            }
            if (l2 == r2 + 1){
                j ++;
                if(j < v2.size()){
                    tie(l2,r2) = v2[j];
                }
            }
        }else{
            //binary search
            int L = 0,R = len_to_check;
            while (R-L > 1){
                int MID = L + R >> 1;
                if (check(l1,l2,MID)){
                    L = MID;
                }else{
                    R = MID;
                }
            }
            if (check(l1,l2,R)){
                len += R;
            }else{
                len += L;
            }
            return len;
        }
    }
    return len;
}
int main(){
    scanf("%d%s",&n,s+1);
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        Heavy_Light_Decomposition::addEdge(u,v);
        Heavy_Light_Decomposition::addEdge(v,u);
    }
    Heavy_Light_Decomposition::init(1);
    int q;
    for (int i=0;i<HASH_CNT;i++){
        hasher[i].init(i,i,S,2*n);
    }
    scanf("%d",&q);
    while (q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        vector<pair<int,int> > v1 = Heavy_Light_Decomposition::lca(a,b),
            v2 = Heavy_Light_Decomposition::lca(c,d);
       // debug(a,b,v1);
        //debug(c,d,v2);
        int ans = work(v1,v2);
        printf("%d\n",ans);
    }
    return 0;
}