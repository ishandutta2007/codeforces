#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 i128;

istream& operator>>(istream &is,i128 &a)
{
    string s;
    is >> s;
    a=0;
    for(char c:s) a=10*a+(c-'0');
    return is;
}

ostream& operator<<(ostream &os,i128 a)
{
    string s;
    do
    {
        s+=char('0'+a%10);
        a/=10;
    }while(a);
    ranges::reverse(s);
    os << s;
    return os;
}

i128 gcd(i128 a,i128 b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

struct ST
{
    int n;
    vector<i128> a;
    vector<i128> tree;
    void build(int idx,int l,int r)
    {
        if(l==r) tree[idx]=a[l];
        else
        {
            int m=(l+r)/2;
            build(2*idx,l,m);
            build(2*idx+1,m+1,r);
            tree[idx]=gcd(tree[2*idx],tree[2*idx+1]);
        }
    }
    void update(int idx,int l,int r,int pos)
    {
        if(l==r) tree[idx]=0;
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos);
            else update(2*idx+1,m+1,r,pos);
            tree[idx]=gcd(tree[2*idx],tree[2*idx+1]);
        }
    }
    i128 val(){return tree[1];}
    void ini(vector<i128> b)
    {
        n=int(b.size())-1;
        a=b;
        tree.assign(4*(n+5),0);
        build(1,1,n);
    }
    void upd(int pos){update(1,1,n,pos);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<i128> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<i128> b(m+1,0);
        for(int j=1;j<=m;j++) cin >> b[j];
        vector l(n+1,vector(m+1,i128(0)));
        vector r(m+1,vector(n+1,i128(0)));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                i128 g=gcd(a[i],b[j]);
                l[i][j]=(a[i]/g);
                r[j][i]=(b[j]/g);
            }
        }
        vector<ST> one(n+1);
        for(int i=1;i<=n;i++) one[i].ini(l[i]);
        vector<ST> two(m+1);
        for(int j=1;j<=m;j++) two[j].ini(r[j]);
        vector<bool> avis(n+1,0);
        vector<bool> bvis(m+1,0);
        int ca=n,cb=m;
        while(1)
        {
            bool mv=0;
            for(int i=1;i<=n;i++)
            {
                if(!avis[i]&&one[i].val()!=1)
                {
                    avis[i]=mv=1;
                    ca--;
                    for(int j=1;j<=m;j++) two[j].upd(i);
                }
            }
            for(int j=1;j<=m;j++)
            {
                if(!bvis[j]&&two[j].val()!=1)
                {
                    bvis[j]=mv=1;
                    cb--;
                    for(int i=1;i<=n;i++) one[i].upd(j);
                }
            }
            if(!mv) break;
        }
        if(ca+cb>0)
        {
            cout << "YES\n";
            cout << ca << " " << cb << "\n";
            for(int i=1;i<=n;i++) if(!avis[i]) cout << a[i] << " ";
            cout << "\n";
            for(int j=1;j<=m;j++) if(!bvis[j]) cout << b[j] << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}