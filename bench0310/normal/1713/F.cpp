#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto build=[&](auto &&self,vector<int> a)->vector<int>
    {
        int n=(int)a.size()-1;
        if(n==1) return {0,a[1]};
        vector<int> l(n/2+1,0);
        for(int i=1;i<=n/2;i++) l[i]=a[i];
        vector<int> x=self(self,l);
        vector<int> r(n/2+1,0);
        for(int i=1;i<=n/2;i++) r[i]=a[i+n/2];
        vector<int> y=self(self,r);
        vector<int> b(n+1,0);
        for(int i=1;i<=n/2;i++) b[i]=(x[i]^y[i]);
        for(int i=1;i<=n/2;i++) b[i+n/2]=y[i];
        return b;
    };
    auto solve=[&](auto &&self,vector<int> b)->vector<int>
    {
        int n=(int)b.size()-1;
        if(n==1) return {0,b[1]};
        if((n&(n-1))==0)
        {
            vector<int> a(n+1,0);
            vector<int> l(n/2+1,0);
            for(int i=1;i<=n/2;i++) l[i]=b[i+n/2];
            vector<int> x=self(self,l);
            for(int i=1;i<=n/2;i++) a[i+n/2]=x[i];
            vector<int> r(n/2+1,0);
            for(int i=1;i<=n/2;i++) r[i]=(b[i]^b[i+n/2]);
            vector<int> y=self(self,r);
            for(int i=1;i<=n/2;i++) a[i]=y[i];
            return a;
        }
        else
        {
            int m=1;
            while(2*m<=n) m*=2;
            int s=n-m;
            vector<int> a(n+1,0);
            vector<int> r(s+1,0);
            for(int i=1;i<=s;i++) r[i]=(b[i]^b[m+i]);
            vector<int> y=self(self,r);
            for(int i=1;i<=s;i++) a[i]=y[i];
            y.insert(y.begin()+1,m-s,0);
            vector<int> tmp=build(build,y);
            vector<int> l(m+1,0);
            for(int i=1;i<=m;i++) l[i]=(b[i]^tmp[i]);
            vector<int> x=self(self,l);
            for(int i=1;i<=m;i++) a[s+i]=x[i];
            return a;
        }
    };
    int n;
    cin >> n;
    vector<int> b(n+1,0);
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<int> a=solve(solve,b);
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    return 0;
}