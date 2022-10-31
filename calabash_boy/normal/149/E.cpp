#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
const int maxS = 1000+50;
char t[105][1050];
struct Seg_Tree{
    int Max[maxS*4],Min[maxS*4];
    int MaxLazy[maxS*4],MinLazy[maxS*4];
    void clear(){
        memset(Max,0,sizeof Max);
        memset(Min,0x3f3f3f3f,sizeof Min);
        memset(MaxLazy,-1,sizeof  MaxLazy);
        memset(MinLazy,-1,sizeof MinLazy);
    }
    void down(int x){
        if (MaxLazy[x] != -1){
            Max[x<<1] = max(Max[x<<1],MaxLazy[x]);
            Max[x<<1|1] = max(Max[x<<1|1],MaxLazy[x]);
            if (MaxLazy[x<<1] == -1)MaxLazy[x<<1] = MaxLazy[x];
            else MaxLazy[x<<1] = max(MaxLazy[x<<1],MaxLazy[x]);
            if (MaxLazy[x<<1|1] == -1)MaxLazy[x<<1|1] = MaxLazy[x];
            else MaxLazy[x<<1|1] = max(MaxLazy[x<<1|1],MaxLazy[x]);
            MaxLazy[x] = -1;
        }
        if (MinLazy[x] != -1){
            Min[x<<1] = min(Min[x<<1],MinLazy[x]);
            Min[x<<1|1] = min(Min[x<<1|1],MinLazy[x]);
            if (MinLazy[x<<1] == -1)MinLazy[x<<1] = MinLazy[x];
            else MinLazy[x<<1] = min(MinLazy[x<<1],MinLazy[x]);
            if (MinLazy[x<<1|1] == -1)MinLazy[x<<1|1] = MinLazy[x];
            else MinLazy[x<<1|1] = min(MinLazy[x<<1|1],MinLazy[x]);
            MinLazy[x] = -1;
        }
    }
    void update_Max(int x,int l,int r,int L,int R,int Val){
        if (l>R || L>r)return;
        if (L<=l && r<=R){
            Max[x] = max(Max[x],Val);
            if (MaxLazy[x] == -1){
                MaxLazy[x] = Val;
            }else{
                MaxLazy[x] = max(MaxLazy[x],Val);
            }
            return;
        }
        int mid = l+r >>1;
        down(x);
        update_Max(x<<1,l,mid,L,R,Val);
        update_Max(x<<1|1,mid+1,r,L,R,Val);
    }
    void update_Min(int x,int l,int r,int L,int R,int Val){
        if (l>R || L>r)return;
        if (L<=l && r<=R){
            Min[x] = min(Min[x],Val);
            if (MinLazy[x] == -1){
                MinLazy[x] = Val;
            }else{
                MinLazy[x] = max(MinLazy[x],Val);
            }
            return;
        }
        int mid = l+r >>1;
        down(x);
        update_Min(x<<1,l,mid,L,R,Val);
        update_Min(x<<1|1,mid+1,r,L,R,Val);
    }
    pair<int,int> query(int x,int l,int r,int L,int R){
        if (l>R || L>r)return {0x3f3f3f3f,0};
        if (L<=l && r<=R){
            return {Min[x],Max[x]};
        }
        int mid = l+r >>1;
        down(x);
        pair<int,int> ql = query(x<<1,l,mid,L,R),qr = query(x<<1|1,mid+1,r,L,R);
        return {min(ql.first,qr.first),max(ql.second,qr.second)};
    }
}tree;
char s[maxn];
int n;
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];/**/
    int num[maxn*2];/**/
    int first_pos[maxn*2],last_pos[maxn*2];
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
        memset(first_pos,0x3f3f3f3f,sizeof first_pos);
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
    void build(){
        memset(cntA,0,sizeof cntA);
        memset(num,0,sizeof num);
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        /**/
        int temp=1;
        for (int i=0;i<n;i++){
            num[temp = nxt[temp][s[i]-'A'] ]=1;
            first_pos[temp] = i+1;
            last_pos[temp] = i+1;
        }
        /**/
        for (int i=cnt;i>=1;i--){
            //basic
            int x = A[i];
            num[fa[x]]+=num[x];
            first_pos[fa[x]] = min(first_pos[fa[x]],first_pos[x]);
            last_pos[fa[x]] = max(last_pos[fa[x]],last_pos[x]);
        }
    }
    int query(int idx){
        int n = strlen(t[idx]);
        int now =1 ;
        for (int i=0;i<n;i++){
            now = nxt[now][t[idx][i] - 'A'];
            tree.update_Min(1,1,n,i+1,i+1,first_pos[now]);
        }
        int temp = now;
        while (temp!=1){
            //cout<<"update max "<<l[fa[temp]]+1<<" "<<l[temp]<<" "<<last_pos[temp]<<endl;
            tree.update_Max(1,1,n,l[fa[temp]]+1,l[temp],last_pos[temp]);
            temp = fa[temp];
        }
        for (int i=1;i<n;i++){
            int l = tree.query(1,1,n,i,i).first;
            int r = tree.query(1,1,n,n-i,n-i).second;
            //cout<<i<<" "<<l<<" "<<r<<endl;
            if (r-l >= n-i)return 1;
        }
        return 0;
    }
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("num[%d]=%d l[%d]=%d fa[%d]=%d\n",i,num[i],i,l[i],i,fa[i]);
        }
    }
}sam;

int main(){
    scanf("%s",s);
    n = strlen(s);
    sam.clear();
    sam.init(s);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        sam.last = 1;
        scanf("%s",&t[i][0]);
        sam.init(t[i]);
    }
    sam.build();
    int ans =0;
    for (int i=1;i<=m;i++){
        tree.clear();
        ans += sam.query(i);
    }
    cout<<ans<<endl;
    return 0;
}