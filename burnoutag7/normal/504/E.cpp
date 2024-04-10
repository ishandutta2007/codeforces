#include<bits/stdc++.h>
using namespace std;

const int SIZ = (1 << 20);
char buf1[SIZ], *pt1 = buf1, *pt2 = buf1;
char buf2[SIZ], *pt3 = buf2, *pt4 = buf2;
char gchar() {
    if (pt1 == pt2)
        pt1 = buf1, pt2 = buf1 + fread(buf1, 1, SIZ, stdin);
    return pt1 == pt2 ? EOF : *pt1++;
}
void pchar(char c) {
    *pt4++ = c;
    if (pt4 - pt3 == SIZ)
        fwrite(buf2, 1, SIZ, stdout), pt4 = buf2;
}
void output() { fwrite(buf2, 1, pt4 - pt3, stdout); }
template <typename T> void read(T &ret) {
    ret = 0;
    static char c;
    while ((c = gchar()) > '9' || c < '0')
        ;
    ret = c - '0';
    while ((c = gchar()) >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
}
void read(char *s) {
    static char c;
    while ((c = gchar()) == ' ' || c == '\n')
        ;
    *s = c;
    s++;
    while ((c = gchar()) != ' ' && c != '\n') {
        *s = c;
        s++;
    }
    *s = '\0';
}
template <typename T> void i_write(T x) { // doesn't support negative integers!
    if (x > 9)
        i_write(x / 10);
    pchar(x % 10 + '0');
}
template <typename T> void write(T x, char end = '\n') {
    if (x < 0)
        pchar('-'), x = -x;
    if (x > 9)
        i_write(x / 10);
    pchar(x % 10 + '0');
    pchar(end);
}

int n;
vector<int> g[300005];
int hson[300005],fa[300005],dep[300005],sz[300005],top[300005],dfn[300005],fin[300005],dfc,rnk[300005];

int hldprec(int x,int p,int d){
    dep[x]=d;
    sz[x]=1;
    for(int& y:g[x])if(y!=p){
        sz[x]+=hldprec(y,x,d+1);
        fa[y]=x;
        if(sz[y]>sz[hson[x]]){
            hson[x]=y;
        }
    }
    return sz[x];
}

void hlddec(int x,int head){
    top[x]=head;
    dfn[x]=++dfc;
    rnk[dfc]=x;
    if(hson[x]){
        hlddec(hson[x],head);
        for(int &y:g[x])if(y!=fa[x]&&y!=hson[x]){
            hlddec(y,y);
        }
    }
    fin[x]=dfc;
}

void path(int u,int v,vector<pair<int,int>>& p){
    static stack<pair<int,int>> st;
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            p.emplace_back(2*n+1-dfn[u],2*n+1-dfn[u]+dep[u]-dep[top[u]]);
            u=fa[top[u]];
        }else{
            st.emplace(dfn[v]-(dep[v]-dep[top[v]]),dfn[v]);
            v=fa[top[v]];
        }
    }
    if(dep[u]>dep[v])p.emplace_back(2*n+1-dfn[u],2*n+1-dfn[v]);
    else p.emplace_back(dfn[u],dfn[v]);
    while(!st.empty()){
        p.emplace_back(st.top());
        st.pop();
    }
}

typedef long long ll;
const int mod=998244353;
char buf[300005],s[600005];
int pw[600005],hs[600005];

int ghs(int l,int r){
    static int res;
    res=hs[r]-(ll)hs[l-1]*pw[r-l+1]%mod;
    return res<0?res+mod:res;
}

int main(){

    read(n);read(buf+1);
    for(int i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    pw[0]=1;
    for(int i=1;i<=2*n;i++){
        s[i]=i<=n?buf[rnk[i]]:s[2*n+1-i];
        pw[i]=pw[i-1]*26ll%mod;
        hs[i]=(hs[i-1]*26ll+s[i]-'a')%mod;
    }
    int q;
    read(q);
    while(q--){
        int a,b,c,d,ans=0;
        read(a);read(b);read(c);read(d);
        if(buf[a]!=buf[c]){
            pchar('0');pchar('\n');
            continue;
        }
        static vector<pair<int,int>> p1,p2;
        p1.clear();p2.clear();
        path(a,b,p1);
        path(c,d,p2);
        for(int i=0,j=0;i<p1.size()&&j<p2.size();){
            auto &[l1,r1]=p1[i];
            auto &[l2,r2]=p2[j];
            int len=min(r1-l1+1,r2-l2+1);
            if(ghs(l1,l1+len-1)!=ghs(l2,l2+len-1)){
                int l=1,r=len-1,m,res=0;
                while(l<=r){
                    m=l+r>>1;
                    if(ghs(l1,l1+m-1)!=ghs(l2,l2+m-1)){
                        r=m-1;
                    }else{
                        l=m+1;
                        res=m;
                    }
                }
                ans+=res;
                break;
            }
            l1+=len;
            l2+=len;
            ans+=len;
            if(l1>r1)i++;
            if(l2>r2)j++;
        }
        write(ans);
    }
    output();

    return 0;
}