#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e4+5)

void comp(vector<int>& p)
{
    int k=p.size();
    vector<bool> mk(k);
    for(int i=0;i<k;i++)
        if(p[i]!=-1)
            mk[p[i]]=1;
    vector<int> pos;
    for(int i=0;i<k;i++)
        if(!mk[i])
            pos.push_back(i);

    int kk=0;
    for(int i=0;i<k;i++)
        if(p[i]==-1)
        {
            p[i]=pos[kk];
            kk++;
        }
}

string build(vector<int> per)
{
    int k=per.size();
    string res="";
    for(int i=0;i<k;i++)
        res.push_back(per[i]+'a');
    return res;
}

string solve(string& s,string& a,string& b,int k,int ty)
{
    int n=a.size();
    vector<int> per(k,-1);
    vector<bool> mk(k);
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        int p=s[i]-'a';
        if(flag)
        {
            if(per[p]!=-1)
                continue;
            if(ty==0)
            {
                for(int i=k-1;i>=0;i--)
                    if(!mk[i])
                    {
                        per[p]=i;
                        mk[i]=1;
                        break;
                    }
            }
            else
            {
                for(int i=0;i<k;i++)
                    if(!mk[i])
                    {
                        per[p]=i;
                        mk[i]=1;
                        break;
                    }
            }
            continue;
        }

        int l=a[i]-'a';
        int r=b[i]-'a';
        if(l==r)
        {
            if(per[p]!=-1)
                continue;
            if(!mk[l])
            {
                per[p]=l;
                mk[l]=1;
            }
            else
                return "0";
            continue;
        }
        if(per[p]!=-1)
        {
            if(per[p]<l || per[p]>r)
                return "0";
            flag=1;
            if(per[p]==l)
                ty=0;
            else if(per[p]==r)
                ty=1;
            continue;
        }
        for(int i=l+1;i<r;i++)
            if(!mk[i])
            {
                per[p]=i;
                mk[i]=1;
                flag=1;
                break;
            }
        if(per[p]!=-1)
            continue;
        if(mk[l] || mk[r])
        {
            if(!mk[l])
            {
                per[p]=l;
                mk[l]=1;
                flag=1;
                ty=0;
            }
            else if(!mk[r])
            {
                per[p]=r;
                mk[r]=1;
                flag=1;
                ty=1;
            }
            else
                return "0";
        }
        else
        {
            if(ty==0)
            {
                per[p]=l;
                mk[l]=1;
                flag=1;
            }
            else
            {
                per[p]=r;
                mk[r]=1;
                flag=1;
            }
        }
    }

    comp(per);

    bool ok=1;
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
            ok&=(per[i]!=per[j]);
    for(int i=0;i<n;i++)
        s[i]='a'+per[s[i]-'a'];
    if(ok && s>=a && s<=b)
        return build(per);
    return "0";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> k;
        string s,a,b;
        cin >> s >> a >> b;
        string ss=s;
        string res=solve(s,a,b,k,1);
        if(res!="0")
        {
            db("YES")
            db(res)
            continue;
        }
//        db(ss)
        res=solve(ss,a,b,k,0);
        if(res=="0")
            db("NO")
        else
        {
            db("YES")
            db(res)
        }
    }

    return 0;
}