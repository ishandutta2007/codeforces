#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];/**/
    int num1[maxn*2],num2[maxn*2];/**/
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
    int build(char *s,char *t){
        int ns = strlen(s);
        int nt = strlen(t);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /**/
        int temp=1;
        for (int i=0;i<ns;i++){
            temp = nxt[temp][s[i]-'a'];
            num1[temp] = 1;
        }
        temp = 1;
        for (int i=0;i<nt;i++){
            temp = nxt[temp][t[i] - 'a'];
            num2[temp] = 1;
        }
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            num1[fa[x]]+=num1[x];
            num2[fa[x]] += num2[x];
        }
        int ans =0x3f3f3f3f;
        for (int i=2;i<=cnt;i++){
            if (num1[i] == num2[i] && num1[i] == 1){
                ans = min(ans,l[fa[i]]+1);
            }
        }
        return ans == 0x3f3f3f3f?-1:ans;
    }
}sam;
char s[maxn],t[maxn];
int main(){
    scanf("%s%s",s,t);
    sam.clear();
    sam.init(s);
    sam.last = 1;
    sam.init(t);
    cout<<sam.build(s,t);
    return 0;
}