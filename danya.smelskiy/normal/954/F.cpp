#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


long long n,m;
long long p[100005];
long long len[100005];
pair<long long,pair<long long,long long> > a[10005];
map<long long,bool> used;
vector<long long> v;
map<long long,int> mt;
long long ans[100];
long long ans2[100];
int q[4][100005];

inline void add(long long x) {
    if (x<1 || x>m) return;
    if (used[x]) return;
    used[x]=true;
    v.push_back(x);
}


struct matrix{
    long long a[4][4];
};

matrix def;

struct matrix mult(matrix x,matrix y) {
    matrix res;
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            res.a[i][j]=0;
            for (int k=0;k<3;++k) {
                res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%md;
            }
        }
    }
    return res;
};

struct matrix pw(matrix x,long long y) {
    if (y==0) return def;
    if (y==1) return x;
    if (y%2ll==1ll) return mult(pw(x,y-1ll),x);
    matrix res=pw(x,y/2ll);
    return mult(res,res);
};

inline void mult2(matrix y) {
    for (int i=0;i<3;++i)
        ans2[i]=0;
    for (int i=0;i<1;++i) {
        for (int j=0;j<3;++j) {
            for (int k=0;k<3;++k)
                ans2[j]=(ans2[j]+ans[k]*y.a[k][j])%md;
        }
    }
    for (int i=0;i<3;++i)
        ans[i]=ans2[i];
}

inline void trs(int x,int y) {
    for (int i=0;i<3;++i)
        ans2[i]=0;
    for (int i=0;i<3;++i)
    if (!(x&(1<<i))) {
        for (int j=0;j<3;++j)
        if (!(y&(1<<j)) && abs(i-j)<=1) {
            ans2[j]=(ans2[j]+ans[i])%md;
        }
    }
    for (int i=0;i<3;++i)
        ans[i]=ans2[i];
}

inline matrix get_matrix(int x) {
    matrix res;
    for (int i=0;i<3;++i)
        for (int j=0;j<3;++j)
            res.a[i][j]=0;
    for (int i=0;i<3;++i)
    if (!(x&(1<<i))) {
        for (int j=0;j<3;++j)
        if (!(x&(1<<j)) && abs(i-j)<=1) {
            res.a[i][j]=1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    add(m);
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
        add(a[i].second.first);
        add(a[i].second.first-1ll);
        add(a[i].second.second);
        add(a[i].second.second+1ll);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i) {
        p[i+1]=v[i];
        mt[v[i]]=i+1;
    }
    for (int i=1;i<=v.size();++i)
        len[i]=p[i]-p[i-1];
    for (int i=1;i<=n;++i) {
        long long x,y;
        x=a[i].second.first;
        y=a[i].second.second;
        x=mt[x];
        y=mt[y];
        int z=a[i].first;
        q[z][x]++;
        q[z][y+1]--;
    }
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j)
            def.a[i][j]=0;
        def.a[i][i]=1;
    }
    for (int i=1;i<=3;++i) {
        for (int j=1;j<=v.size();++j) {
            q[i][j]+=q[i][j-1];
        }
    }
    ans[1]=1;
    matrix cc=get_matrix(0);
    cc=pw(cc,len[1]-1);
    mult2(cc);
    int last=0;
    for (int i=2;i<=v.size();++i) {
        int nw=0;
        for (int j=1;j<=3;++j)
            if (q[j][i]) nw+=(1<<(j-1));
        trs(last,nw);
        cc=get_matrix(nw);
        cc=pw(cc,len[i]-1);
        mult2(cc);
    }
    cout<<ans[1];
}