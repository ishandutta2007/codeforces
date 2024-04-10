#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> r,c;
    for(int i=0;i<10;i+=2)
    {
        int sz=r.size();
        r.push_back(1<<i);
        c.push_back(1<<(i+1));
        for(int j=0;j<sz;j++)
        {
            r.push_back(r[j]);
            c.push_back(c[j]);
        }
    }
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n-1;j++) cout << c[j] << " ";
        cout << endl;
    }
    for(int j=0;j<n-1;j++)
    {
        for(int i=1;i<=n;i++) cout << r[j] << " ";
        cout << endl;
    }
    auto p=[&](vector<int> &v,int a,int x)->int
    {
        if(x==0) return a;
        int y=0;
        for(int i=a;i<n;i++)
        {
            y^=v[i];
            if(y==x) return i+1;
        }
        y=0;
        for(int i=a-1;i>=0;i--)
        {
            y^=v[i];
            if(y==x) return i;
        }
        return -1;
    };
    int a=0,b=0;
    while(k--)
    {
        int x;
        cin >> x;
        a=p(r,a,x&(0b0101010101));
        b=p(c,b,x&(0b1010101010));
        cout << a+1 << " " << b+1 << endl;
    }
    return 0;
}