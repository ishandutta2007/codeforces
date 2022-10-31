#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
char s[maxn];
int n;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    int used[maxn*2];
    //extension
    int cntA[maxn*2],A[maxn*2];/**/
    int num[maxn*2];/**/
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
        memset(cntA,0,sizeof cntA);
        memset(num,0,sizeof num);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /**/
        int temp=1;
        for (int i=0;i<n;i++){
            num[temp = nxt[temp][s[i]-'a'] ]=1;
        }
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            num[fa[x]]+=num[x];
        }
    }
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("num[%d]=%d l[%d]=%d fa[%d]=%d\n",i,num[i],i,l[i],i,fa[i]);
        }
    }
}sam;
int main(){
    scanf("%s",s);
    /* calc n must before sam.init()*/
    n = strlen(s);
    sam.init(s);
    sam.build();
    int q;
    scanf("%d",&q);
    for (int _ = 1;_ <= q;_ ++){
        scanf("%s",s);
        int n = strlen(s);
        for (int i=n;i<2*n;i++){
            s[i] = s[i-n];
        }
        long long ans =0;
        int now = 1;
        int len = 0;
        int N = 2*n-1;
        for (int i=0;i<N;i++){
            while (now !=1 && !sam.nxt[now][s[i] - 'a'])now = sam.fa[now],len = sam.l[now];
            if (sam.nxt[now][s[i] - 'a'])now = sam.nxt[now][s[i] - 'a'],len++;
            if (i >= n && len == n+1){
                len --;
                if (sam.l[sam.fa[now]] == len)now = sam.fa[now];
            }
            if (len == n && sam.used[now]!= _) ans += sam.num[now],sam.used[now] = _;
        }
        printf("%lld\n",ans);
    }

    return 0;
}