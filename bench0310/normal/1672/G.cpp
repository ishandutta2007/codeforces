#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;

struct mi
{
    int v;
    mi(){v=0;}
    mi(ll _v){v=int(-mod<=_v&&_v<mod?_v:_v%mod); if(v<0)v+=mod;}
    explicit operator int()const{return v;}
    friend bool operator==(const mi &a,const mi &b){return (a.v==b.v);}
    friend bool operator!=(const mi &a,const mi &b){return (a.v!=b.v);}
    friend bool operator<(const mi &a,const mi &b){return (a.v<b.v);}
    mi& operator+=(const mi &m){if((v+=m.v)>=mod)v-=mod; return *this;}
    mi& operator-=(const mi &m){if((v-=m.v)<0)v+=mod; return *this;}
    mi& operator*=(const mi &m){v=(ll(v)*m.v)%mod; return *this;}
    mi& operator/=(const mi &m){return (*this)*=inv(m);}
    friend mi pow(mi a,ll e){mi r=1; for(;e;a*=a,e/=2)if(e&1)r*=a; return r;}
    friend mi inv(mi a){return pow(a,mod-2);}
    mi operator-()const{return mi(-v);}
    mi& operator++(){return (*this)+=1;}
    mi& operator--(){return (*this)-=1;}
    friend mi operator++(mi &a,int){mi t=a; ++a; return t;}
    friend mi operator--(mi &a,int){mi t=a; --a; return t;}
    friend mi operator+(mi a,const mi &b){return a+=b;}
    friend mi operator-(mi a,const mi &b){return a-=b;}
    friend mi operator*(mi a,const mi &b){return a*=b;}
    friend mi operator/(mi a,const mi &b){return a/=b;}
    friend istream& operator>>(istream &is,mi &m){ll _v; is >> _v; m=mi(_v); return is;}
    friend ostream& operator<<(ostream &os,const mi &m){os << m.v; return os;}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    array<int,3> c={0,0,0};
    for(int i=0;i<n;i++) for(char a:s[i]) c[(a!='?'?(a-'0'):2)]++;
    mi res=0;
    if(n==1||m==1) res=((c[0]==0||c[1]==0)?2:0);
    else if((n%2)==0&&(m%2)==0) res=pow(mi(2),c[2]);
    else if((n%2)!=(m%2))
    {
        if(m&1)
        {
            vector<string> t(m,string(n,'$'));
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) t[j][i]=s[i][j];
            swap(n,m);
            s=t;
        }
        for(int t=0;t<2;t++)
        {
            mi now=1;
            for(int j=0;j<m;j++)
            {
                int x=0,cnt=0;
                for(int i=0;i<n;i++)
                {
                    if(s[i][j]!='?') x^=(s[i][j]-'0');
                    else cnt++;
                }
                if(cnt>0) now*=pow(mi(2),cnt-1);
                else if(x!=t) now=0;
            }
            res+=now;
        }
    }
    else
    {
        vector<int> v[n+m];
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='1')
                {
                    row[i]^=1;
                    col[j]^=1;
                }
                if(s[i][j]=='?')
                {
                    v[i].push_back(n+j);
                    v[n+j].push_back(i);
                }
            }
        }
        for(int t=0;t<2;t++)
        {
            mi now=1;
            vector<bool> vis(n+m,0);
            for(int i=0;i<n+m;i++)
            {
                if(vis[i]) continue;
                int sz=0;
                int edges=0;
                queue<int> q;
                int x=0;
                auto add=[&](int a)
                {
                    if(!vis[a])
                    {
                        q.push(a);
                        vis[a]=1;
                        if(a<n) x^=row[a];
                        else x^=col[a-n];
                        sz++;
                        if(a<n) edges+=(v[a].size());
                    }
                };
                add(i);
                while(!q.empty())
                {
                    int a=q.front();
                    q.pop();
                    for(int to:v[a]) add(to);
                }
                if((t&sz&1)==x) now*=pow(mi(2),edges-(sz-1));
                else now=0;
            }
            res+=now;
        }
    }
    cout << res << "\n";
    return 0;
}