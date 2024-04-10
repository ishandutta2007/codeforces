#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        const int sz=20;
        auto basek=[&](int a)->vector<int>
        {
            vector<int> v(sz,0);
            for(int i=0;i<sz;i++)
            {
                v[i]=(a%k);
                a/=k;
            }
            return v;
        };
        auto base10=[&](vector<int> a)->int
        {
            int r=0;
            for(int i=sz-1;i>=0;i--) r=k*r+a[i];
            return r;
        };
        auto add=[&](vector<int> a,vector<int> b)->vector<int>
        {
            vector<int> c(sz,0);
            for(int i=0;i<sz;i++) c[i]=(a[i]+b[i])%k;
            return c;
        };
        auto sub=[&](vector<int> a,vector<int> b)->vector<int>
        {
            vector<int> c(sz,0);
            for(int i=0;i<sz;i++) c[i]=(a[i]-b[i]+k)%k;
            return c;
        };
        int b=1;
        vector<int> s(sz,0);
        for(int i=0;i<n;i++)
        {
            vector<int> now=basek(i);
            if(b==-1) now=sub(basek(0),now);
            now=add(now,s);
            cout << base10(now) << "\n";
            cout.flush();
            int r;
            cin >> r;
            if(r==1) break;
            if(r==-1) exit(0);
            s=basek(i);
            if(b==-1) s=sub(basek(0),s);
            b=-b;
        }
    }
    return 0;
}