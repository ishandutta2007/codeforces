//
// Created by calabash_boy on 18-10-18.
//
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif

typedef unsigned long long ULL;

/************* header ******************/
const int maxn = 1e4+100;
const int maxm = 1e5+100;
const int maxc = 1e6+100 + maxm;
const ULL Seed = 27;
const ULL Mod = 998244353;
char S[maxc];
int pos[maxm];
int len[maxm];
char s[maxn];
int dp[maxn];
int n,m;
struct Trie{
    int nxt[maxc][26];
    int flag[maxc];
    int cnt=0;
    int root =0;
    int newnode(){
        return ++cnt;
    }
    int id(int x){
        if (x >= 'A' && x <= 'Z')return x-'A';
        return x - 'a' ;
    }
    void insert(char *s,int label){
        int now = root;
        while (*s){
            int i = id(*s);
            if (!nxt[now][i])nxt[now][i] = newnode();
            now = nxt[now][i];
            s++;
        }
        flag[now] = label;
    }
}tree;

int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d",&m);
    int now = 1;
    for (int i=1;i<=m;i++){
        scanf("%s",S+now);
        pos[i] = now;
        len[i] = strlen(S+now);
        tree.insert(S+now,i);
        now += len[i]+1;

    }
    for (int i=1;i<=n;i++){
        int tmp = tree.root;
        for (int l = 1;l<=1000;l++){
            int j = i-l;
            if (j<0)break;
            int x = tree.id(s[j+1]);
            tmp = tree.nxt[tmp][x];
            if (!tmp)break;
            int id = tree.flag[tmp];
            if (!id)continue;
            if (dp[j] || j == 0){
                dp[i] = id;
                break;
            }
        }
    }
    assert(dp[n]);
    now = n;
    vector<int> ans(0);
    while (now){
        ans.push_back(dp[now]);
        now -= len[dp[now]];
    }
    reverse(ans.begin(),ans.end());
    for (int x : ans)printf("%s ",&S[pos[x]]);
    puts("");
    return 0;
}