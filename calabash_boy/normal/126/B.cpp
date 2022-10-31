#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 1e6+100;
char s[maxn];
int n;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2];
    int l[maxn*2];
    int last_pos[maxn*2];
    int cntA[maxn*2],A[maxn*2];
    int pos[maxn*2];
    int last,cnt;
    Suffix_Automaton(){
        clear();
    }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        char *S = s;
        while (*s){
            add(*s-'a');
            s++;
        }
        build (S);
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
    void build(char *s){
        int idx = 0;
        int now = 1;
        while (*s){
            idx++;
            int id = *s - 'a';
            now = nxt[now][id];
            if (idx != n){
                pos[idx] = now;
                last_pos[now] = idx;
            }
            s++;
        }
    }
    void build(){
        memset(cntA,0,sizeof cntA);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=n;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            last_pos[fa[x]] = max(last_pos[fa[x]],last_pos[x]);
        }
    }
}sam;
struct KMP{
    int nxt[maxn];
    int len;
    char t[maxn];
    void clear(){
        len =0;
        nxt[0] = nxt[1] =0;
    }
    /* 1-bas */
    /* ss\0 */
    void init(char* ss){
        len = strlen(ss+1);
        memcpy(t,ss,(len+2)*sizeof(char));
        for (int i=2;i<=len;i++){
            nxt[i] = nxt[i-1];
            while (nxt[i]&&ss[i]!=ss[nxt[i]+1]) nxt[i] = nxt[nxt[i]];
            nxt[i]+=(ss[i]==ss[nxt[i]+1]);
        }
    }
    /* ssstart_pos. first_onlytrue*/
    vector<int> match(char *ss,bool first_only = false){
        int len_s = strlen(ss+1);
        vector<int> start_pos(0);
        for (int i=1,j=1;i<=len_s;){
            while (j!=1 && ss[i] != t[j])j = nxt[j-1]+1;
            if (ss[i] == t[j]) j++,i++;
            else i++;
            if (j == len+1){
                start_pos.push_back(i-j+1);
                if (first_only)return start_pos;
                j = nxt[len]+1;
            }
        }
        return start_pos;
    }
    void debug(){
        for (int i=0;i<=len;i++){
            printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
//            Debug(nxt[i]);
        }
    }
    /*   acaca  ac  */
    vector<int> periodic(){
        vector<int> ret;
        int now = len;
        while (now){
            now = nxt[now];
            ret.push_back(len-now);
        }
        return ret;
    }
    /*   acac acacacaca*/
    vector<int> periodic_loop(){
        vector<int>ret ;
        for (int x :periodic()){
            if (len%x==0){
                ret.push_back(x);
            }
        }
        return ret;
    }
    int min_periodic_loop(){
        return periodic_loop()[0];
    }
    void solve(){
        for (int now = nxt[n];now;now = nxt[now]){
            int pos = sam.pos[now];
            cerr<<now<<endl;
            if (sam.last_pos[pos] > now){
                s[now+1] = '\0';
                puts(s+1);
                return;
            }
        }
        puts("Just a legend");
    }
}kmper;
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    kmper.init(s);
    cerr<<"kmper init "<<endl;
    sam.init(s+1);
    sam.build();
    //kmper.debug();
    cerr<<"sam build"<<endl;
    kmper.solve();
    return 0;
}