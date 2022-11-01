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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> a(n+1,0);
    int s=0;
    vector<double> c(n+1,0);
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s+=(a[i]<x);
        c[s]++;
    }
    vector<double> d=c;
    ranges::reverse(d);
    vector<double> v=conv(c,d);
    vector<ll> res(n+1,0);
    for(int i=0;i<=n;i++) res[i]=round(v[n+i]);
    for(int i=0;i<=n;i++) res[0]-=(ll(c[i])*(ll(c[i])+1)/2);
    for(int i=0;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}