#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5+100;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];/**/
    int num[maxn*2];/**/
    int label[maxn*2];
    bool used[maxn*2];
    Suffix_Automaton(){
        clear();
    }
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
        l[np] = l[p]+1;
        last = np;
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
    }
    void build(char *s,pair<int,int> limit,int Label){
        int n = strlen(s);
        memset(num,0,sizeof num);
        int temp=1;
        for (int i=0;i<n;i++){
            num[temp = nxt[temp][s[i]-'a'] ]=1;
        }
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            num[fa[x]]+=num[x];
            if (num[x] >= limit.first && num[x] <= limit.second && label[x] == Label -1){
                label[x] = Label;
            }
        }
    }
    long long query(char *s ,int N){
        long long ans =0;
        int now =1;
        while (*s){
            int id = *s - 'a';
            now = nxt[now][id];
            int temp = now;
            while (temp !=1 && !used[temp]){
                used[temp] = 1;
                if (label[temp] == N)ans += l[temp] - l[fa[temp]];
                temp = fa[temp];
            }
            s++;
        }
        return ans;
    }
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("num[%d]=%d l[%d]=%d fa[%d]=%d\n",i,num[i],i,l[i],i,fa[i]);
        }
    }
}sam;
char s[50005];
char t[10][50005];
pair<int,int> limit[10];
int n;
int main(){
    scanf("%s",s);
    sam.init(s);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s %d %d",&t[i][0],&limit[i].first,&limit[i].second);
        sam.last = 1;
        sam.init(t[i]);
    }
    sam.build();
    for (int i=0;i<n;i++){
        sam.build(t[i],limit[i],i+1);
    }
    cout<<sam.query(s,n)<<endl;
    return 0;
}