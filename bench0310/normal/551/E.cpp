#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int inf=1000000001;

struct bucket
{
    int n;
    int off;
    unordered_map<int,array<int,2>> m;
    vector<int> a;
    int x;
    void build(vector<int> &t,int l,int r)
    {
        for(int i=l;i<=r;i++) a.push_back(t[i]);
        off=l;
        x=0;
        n=a.size();
        m.reserve(n);
        m.max_load_factor(0.25);
        for(int i=n-1;i>=0;i--) m[a[i]][0]=i;
        for(int i=0;i<n;i++) m[a[i]][1]=i;
//        cout << "building [" << a[0];
//        for(int i=1;i<n;i++) cout << "," << a[i];
//        cout << "]" << endl;
    }
    void update(int l,int r,int y)
    {
        l-=off;
        r-=off;
        if(l==0&&r==n-1) x=min(x+y,inf);
        else
        {
            m.clear();
            for(int i=0;i<n;i++)
            {
                a[i]=min(a[i]+x,inf);
                if(l<=i&&i<=r) a[i]=min(a[i]+y,inf);
            }
            x=0;
            for(int i=n-1;i>=0;i--) if(a[i]<inf) m[a[i]][0]=i;
            for(int i=0;i<n;i++) if(a[i]<inf) m[a[i]][1]=i;
        }
    }
    array<int,2> query(int y)
    {
//        cout << "query [" << a[0]+x;
//        for(int i=1;i<n;i++) cout << "," << a[i]+x;
//        cout << "] with " << y << endl;
        auto it=m.find(y-x);
        if(it==m.end()) return {-1,-1};
        else return {off+it->second[0],off+it->second[1]};
//        cout << "return [" << res[0] << "," << res[1] << "]" << endl;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    const int sz=707;
    vector<bucket> v((n-1)/sz+1);
    for(int i=0;i*sz<n;i++)
    {
        v[i].build(a,i*sz,min(i*sz+sz-1,n-1));
    }
    while(q--)
    {
        int t,l,r,x;
        cin >> t;
        if(t==1)
        {
            cin >> l >> r >> x;
            l--;
            r--;
            for(int i=l/sz;i<=r/sz;i++) v[i].update(max(l,i*sz),min(r,i*sz+sz-1),x);
        }
        else
        {
            cin >> x;
            l=n;
            r=-1;
            for(int i=0;i<=(n-1)/sz;i++)
            {
                array<int,2> res=v[i].query(x);
                if(res[0]!=-1) l=min(l,res[0]);
                if(res[1]!=-1) r=max(r,res[1]);
            }
            if(r==-1) l=0;
            cout << r-l << "\n";
        }
    }
    return 0;
}