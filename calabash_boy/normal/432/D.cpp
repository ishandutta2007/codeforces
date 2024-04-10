#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
/*lparent*/
int n;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];/**/
    int num[maxn*2];/**/
    //special
    int label[maxn*2];
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'A');
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
    vector<pair<int,int> > build(char *s){
        vector<pair<int,int> > ans(0);
        memset(cntA,0,sizeof cntA);
        memset(num,0,sizeof num);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=n;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /**/
        int temp=1;
        for (int i=0;i<n;i++){
            temp = nxt[temp][s[i]-'A'];
            label[temp]|=1;
            num[temp] = 1;
        }
        while (temp){
            label[temp]|=2;
            temp = fa[temp];
        }
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            if (label[x] == 3){
                ans.push_back({l[x],num[x]});
            }
            num[fa[x]]+=num[x];
        }
        return ans;
    }
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("num[%d]=%d l[%d]=%d fa[%d]=%d label[%d]=%d\n",i,num[i],i,l[i],i,fa[i],i,label[i]);
        }
    }
}sam;
char s[maxn];
int main(){
    scanf("%s",s);
    n = strlen(s);
    sam.clear();
    sam.init(s);

    vector<pair<int,int> > ans = sam.build(s);
    //sam.debug();
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (auto pr : ans){
        printf("%d %d\n",pr.first,pr.second);
    }
    return 0;
}