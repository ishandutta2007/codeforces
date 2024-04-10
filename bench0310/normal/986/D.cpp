#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef complex<double> cd;
void fft(vector<cd> &a)
{
    int n=a.size(),L=31-__builtin_clz(n);
    vector<int> rev(n);
    for(int i=0;i<n;i++) rev[i]=(rev[i/2]+((i&1)<<L))/2;
    for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    static vector<complex<long double>> R(2,1);
    static vector<cd> rt(2,1);
    for(static int k=2;k<n;k*=2)
    {
        R.resize(n); rt.resize(n);
        auto z=polar(1.0L,acos(-1.0L)/k);
        for(int i=k;i<2*k;i++) rt[i]=R[i]=R[i/2]*((i&1)?z:1);
    }
    for(int k=1;k<n;k*=2)
    {
        for(int i=0;i<n;i+=2*k)
        {
            for(int j=0;j<k;j++)
            {
                cd z=rt[j+k]*a[i+j+k];
                a[i+j+k]=a[i+j]-z;
                a[i+j]+=z;
            }
        }
    }
}

vector<double> conv(vector<double> &a,vector<double> &b)
{
    int sa=a.size(),sb=b.size();
    if(sa==0||sb==0) return {};
    int n=1<<(32-__builtin_clz(sa+sb-2));
    vector<cd> f(n),h(n);
    for(int i=0;i<n;i++) f[i]=cd((i<sa?a[i]:0),(i<sb?b[i]:0));
    fft(f);
    for(cd &c:f) c*=c;
    for(int i=0;i<n;i++) h[i]=(f[(-i)&(n-1)]-conj(f[i]));
    fft(h);
    vector<double> c(sa+sb-1);
    for(int i=0;i<sa+sb-1;i++) c[i]=imag(h[i])/(4*n);
    return c;
}

vector<int> mul(vector<int> a,vector<int> b)
{
    int n=a.size();
    int m=b.size();
    vector<double> p(a.begin(),a.end());
    vector<double> q(b.begin(),b.end());
    vector<double> r=conv(p,q);
    ll t=0;
    vector<int> c;
    for(int i=0;(i<n+m-1)||(t>0);i++)
    {
        if(i<n+m-1) t+=ll(r[i]+0.5);
        c.push_back(t%1000);
        t/=1000;
    }
    return c;
}

bool smaller(vector<int> a,vector<int> b)
{
    if(a.size()!=b.size()) return (a.size()<b.size());
    int n=a.size();
    for(int i=n-1;i>=0;i--) if(a[i]!=b[i]) return (a[i]<b[i]);
    return 0;
}

vector<int> mul_small(vector<int> a,int b)
{
    int n=a.size();
    vector<int> c;
    int t=0;
    for(int i=0;i<n||t>0;i++)
    {
        if(i<n) t+=(a[i]*b);
        c.push_back(t%1000);
        t/=1000;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> n;
    string s;
    cin >> s;
    int e=max(0,(int)(((int)s.size()-1)*(log(10)/log(3)))-3);
    while((s.size()%3)!=0) s="0"+s;
    for(int i=0;i<(int)s.size();i+=3) n.push_back(stoi(s.substr(i,3)));
    ranges::reverse(n);
    int res=(1<<30);
    int now=3*e;
    vector<int> b={3};
    vector<int> r={1};
    while(e)
    {
        if(e&1) r=mul(r,b);
        b=mul(b,b);
        e/=2;
    }
    for(int x=0;x<=6;x++)
    {
        for(int y=0;y<=2;y++)
        {
            int tmp=1;
            for(int i=0;i<x;i++) tmp*=3;
            for(int i=0;i<y;i++) tmp*=2;
            if(!smaller(mul_small(r,tmp),n)) res=min(res,now+3*x+2*y);
        }
    }
    if(n==vector<int>{1}) res=1;
    cout << res << "\n";
    return 0;
}