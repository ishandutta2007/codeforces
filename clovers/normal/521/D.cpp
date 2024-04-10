#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
typedef pair<int,int> pii;
#define mk make_pair 
const int N=200005;
vector<pii> mul[N],add[N];
pii change[N];
int now[N],opt[N];
int n,m,k,a[N];
struct node{
    double ch; int id,pos;
    bool operator < (const node &rhs) const{//completely distincted!!
        if(ch==rhs.ch) return id>rhs.id;
        return ch>rhs.ch;
    } 
    node(){}
    node(double ch,int id,int pos):ch(ch),id(id),pos(pos){}
};
set<node> st;

bool cmp(int x,int y){return x>y;}
int pre[N];
void init()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),change[i].first=0;
    for(int i=1;i<=m;i++)
    {
        int pos,val;
        scanf("%lld%lld%lld",&opt[i],&pos,&val);
        if(opt[i]==1) 
        {
            if(max(change[pos].first,a[pos])<val) change[pos]=mk(val,i); 
        }
        else if(opt[i]==2) add[pos].push_back(mk(val,i));
        else mul[pos].push_back(mk(val,i));
    }
    for(int i=1;i<=n;i++)
    {
        if(change[i].first) 
            add[i].push_back(mk(change[i].first-a[i],change[i].second));
    }
    for(int i=1;i<=n;i++) 
    {
        sort(add[i].begin(),add[i].end());
        sort(mul[i].begin(),mul[i].end());
    }
}

double delta(int from,int to){return 1.0*to/from;}
vector<pii> used_add[N],used_mul[N];
int used_change[N];
void solve()
{
    memset(used_change,0,sizeof(used_change));
    for(int i=1;i<=n;i++) 
    {
        if(!add[i].empty())
        {
            double tmp=delta(a[i],a[i]+add[i].back().first);
            st.insert(node(tmp,add[i].back().second,i));
        }
        if(!mul[i].empty())
        {
            double tmp=1.0*mul[i].back().first;
            st.insert(node(tmp,mul[i].back().second,i));
        }
    } 

    for(int i=1;i<=n;i++) now[i]=a[i];
    while(!st.empty()&&k>0)
    {
        node u=*st.begin(); st.erase(u); k--;
        if(opt[u.id]==2||opt[u.id]==1) 
        {
            if(opt[u.id]==1) used_change[u.pos]=1;
            now[u.pos]+=add[u.pos].back().first;
            used_add[u.pos].push_back(add[u.pos].back());
            add[u.pos].pop_back();
            if(!add[u.pos].empty())
            {
                double tmp=delta(now[u.pos],now[u.pos]+add[u.pos].back().first);
                st.insert(node(tmp,add[u.pos].back().second,u.pos));
            }
        }
        else
        {
            used_mul[u.pos].push_back(mul[u.pos].back());
            mul[u.pos].pop_back();
            if(!mul[u.pos].empty())
            {
                double tmp=1.0*mul[u.pos].back().first;
                st.insert(node(tmp,mul[u.pos].back().second,u.pos));
            }
        }
    }
}

vector<int> ANS;
void print()
{
    for(int i=1;i<=n;i++)
    {
        if(used_change[i]) ANS.push_back(change[i].second);
        for(int j=0;j<(int)used_add[i].size();j++)
        {
            if(opt[used_add[i][j].second]==2)
                ANS.push_back(used_add[i][j].second);
        }
        for(int j=0;j<(int)used_mul[i].size();j++)
            ANS.push_back(used_mul[i][j].second);
    }
    printf("%lld\n",(int)ANS.size());
    for(int i=0;i<(int)ANS.size();i++) printf("%lld ",ANS[i]);
}

signed main()
{
    init();
    solve();
    print();
    return 0;
}