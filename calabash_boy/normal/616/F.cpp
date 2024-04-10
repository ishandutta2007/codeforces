// Created by calabash_boy on 18-6-4.
//SPOJ substring
// calc ans_i==i
#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e5+100;
typedef long long ll;
int sa[maxn*2];
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension

    int cntA[maxn*2],A[maxn*2];/**/
    int num[maxn*2];/**/
    ll val[maxn*2];
    int tag[maxn*2];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');s++;
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
                fa[nq] =fa[q];fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
    void build(){
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        for (int i=1;i<=cnt;i++){
            sa[A[i]] = i;
        }
    }
    void build(char *s,ll c,int Tag){
        int temp = 1;
        vector<int> nodes(0);
        while (*s){
            temp = nxt[temp][*s - 'a'];
            int t = temp;
            while (t != 1 && tag[t] != Tag)tag[t] = Tag,nodes.push_back(t),t = fa[t];
            num[temp] = 1;
            s++;
        }
        sort(nodes.begin(),nodes.end(),[](int x,int y){
            return sa[x] > sa[y];
        });
        for (int x : nodes){
            val[x] += num[x] * c;
            num[fa[x]] += num[x];
            num[x] = 0;
        }

    }
    ll query(){
        ll res = 0;
        for (int i=1;i<=cnt;i++){
            res = max(res,val[i] * l[i]);
        }
        return res;
    }
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("num[%d]=%d l[%d]=%d fa[%d]=%d\n",i,num[i],i,l[i],i,fa[i]);
        }
    }
}sam;
char S[maxn];
int st_pos[maxn];
int n;
ll c[maxn];
int main(){
    scanf("%d",&n);
    int now = 0;
    for (int i=0;i<n;i++){
        st_pos[i] = now;
        scanf("%s",S+now);
        now += strlen(S+now) + 1;
        sam.init(S+ st_pos[i]);
        sam.last = 1;
    }
    for (int i =0 ;i<n;i++){
        scanf("%lld",c+i);
    }
    sam.build();
    for (int i=0;i<n;i++){
        sam.build(S + st_pos[i],c[i],i+1);
    }
    printf("%lld\n",sam.query());
    return 0;
}