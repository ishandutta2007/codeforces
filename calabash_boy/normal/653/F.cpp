// Created by calabash_boy on 18-6-4.
//SPOJ substring
// calc ans_i==i
#include<bits/stdc++.h>
using namespace std;
const int maxn = 55e4+100;
char s[maxn];int n;
inline int id(char ch){
    if (ch == '(')return 0;
    else return 1;
}
int sum[maxn];
int l[maxn];
map<int,vector<int> > pos;
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][2],fa[maxn*2],l[maxn*2];
    int last,cnt;
    int endpos[maxn*2];
    int cntA[maxn*2],A[maxn*2];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(id(*s));s++;
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
    long long build(){
        int now = 1;
        for (int i=1;i<=n;i++){
            endpos[now = nxt[now][id(s[i])]] = i;
        }
        memset(cntA,0,sizeof cntA);
//        memset(num,0,sizeof num);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            if (!endpos[fa[x]])endpos[fa[x]] = endpos[x];
        }
        long long ans =0;
        for (int i=2;i<=cnt;i++){
            int r = endpos[i];
            int ll = ::l[r] ;
            vector<int> & V = pos[sum[r]];
         //   cerr<<"! "<<ll<<" "<<r<<"     "<<l[i]<<" "<<l[fa[i]]<<endl;
            int L = max(ll,r - l[i] );
            int R = min(r,r - (l[fa[i]]));
            if (R<L || s[r] == '(')continue;
            //for (auto x : V)cerr<<x<<" ";
            //cerr<<endl;
           // cerr<<r <<" "<<L<<","<<R<<"  "<<lower_bound(V.begin(),V.end(),R) - V.begin() <<" "<< lower_bound(V.begin(),V.end(),L) - V.begin()<<endl;
            ans += lower_bound(V.begin(),V.end(),R) - lower_bound(V.begin(),V.end(),L);
        }
        return ans;
    }
}sam;
int stk[maxn],top;
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
//    n = strlen(s+1);
    sam.clear();
    sam.init(s+1);
    pos[0].push_back(0);
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1];
        if (s[i] == '(')sum[i] ++;
        else sum[i] --;
        pos[sum[i]].push_back(i);
    }
    top = 1;
    stk[0] = 0;
    sum[0] = -0x3f3f3f3f;
    for (int i=1;i<=n;i++){
        while (sum[stk[top-1]] >= sum[i])top--;
        l[i] = stk[top-1];
        stk[top++] = i;
    }
    printf("%lld\n",sam.build());
    return 0;
}
/*
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
 */