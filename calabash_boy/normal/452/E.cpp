// Created by calabash_boy on 18-6-4.
//SPOJ substring
// calc ans_i==i
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
const int mod = 1e9+7;
long long sum[maxn];
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];/**/
    int num1[maxn*2],num2[maxn*2],num3[maxn*2];/**/
    int mask[maxn*2];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');
            s++;
        }
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p]+1;last = np;
        while (p&&!nxt[p][c])nxt[p][c] = np,p = fa[p];
        if (!p)fa[np]=1;
        else{
            int q = nxt[p][c];
            if (l[q]==l[p]+1)fa[np] =q;
            else{
                int nq = ++ cnt;
                l[nq] = l[p]+1;
                memcpy(nxt[nq],nxt[q],sizeof (nxt[q]));
                fa[nq] =fa[q];
                fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
    void build(){
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
    }
    void build(const char *s,int len,int dig){
        int now = 1;
        int M = 1<<(dig-1);
        for (int i=0;i<len;i++){
            now = nxt[now][s[i] - 'a'];
            mask[now] |= M;
            if (dig == 1)num1[now] ++;
            else if (dig == 2)num2[now] ++;
            else if (dig == 3)num3[now] ++;
            else assert(0);
        }
    }
    void query(){
        for (int i=cnt;i>=1;i--){
            int x = A[i];
            mask[fa[x]] |= mask[x];
            num1[fa[x]] += num1[x];
            num2[fa[x]] += num2[x];
            num3[fa[x]] += num3[x];
            if (mask[x] == 7) {
               // cerr<<num1[x] <<" "<<num2[x] <<" "<<num3[x]<<endl;
                long long ans = 1ll * num1[x] * num2[x] % mod * num3[x] % mod;
                (sum[l[x]+1] += mod - ans) %= mod;
                (sum[l[fa[x]]+1] += ans) %= mod;
            }
        }
    }
    void debug(){
        for (int i=1;i<=cnt;i++){
            printf("mask[%d]=%d\n",i,mask[i]);
        }
    }
}sam;
char s1[maxn],s2[maxn],s3[maxn];
int len1,len2,len3;
int main(){
    scanf("%s%s%s",s1,s2,s3);
    len1 = strlen(s1);
    len2 = strlen(s2);
    len3 = strlen(s3);
    sam.init(s1);
    sam.last = 1;
    sam.init(s2);
    sam.last = 1;
    sam.init(s3);
    sam.build();
    sam.build(s1,len1,1);
    sam.build(s2,len2,2);
    sam.build(s3,len3,3);
    sam.query();
//    sam.debug();
    int len = min(min(len1,len2),len3);
    for (int i=1;i<=len;i++){
        (sum[i] += sum[i-1]) %= mod;
        printf("%lld ",sum[i]);
    }
    puts("");
    return 0;
}