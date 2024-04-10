#include <iostream>

using namespace std;
int n, q, a[200000], tree[800000], lev[200001], prav[200001];
void build(int v, int l, int r)
{
    if(r-l==1)
        tree[v]=a[l];
    else
    {
        int m=(l+r)/2;
        build(2*v+1, l, m);
        build(2*v+2, m, r);
        tree[v]=min(tree[2*v+1], tree[2*v+2]);
    }
}
int get(int v, int l, int r, int L, int R)
{
    if(l>=L && r<=R)
        return tree[v];
    if(l>=R || r<=L)
        return 1000000000;
    int m=(l+r)/2;
    return min(get(2*v+1, l, m, L, R), get(2*v+2, m, r, L, R));
}

int main()
{
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<=q;i++)
    {
        lev[i]=-1;
        prav[i]=-1;
    }
    bool kq=false;
    for(int i=0;i<n;i++)
        if(a[i]==q)
        kq=true;
    if(a[0]==0 && kq)
        a[0]=1;
    for(int i=0;i<n;i++)
    {
        if(!kq && a[i]==0)
        {
            kq=true;
            a[i]=q;
        }
        if(a[i]==0)
        a[i]=a[i-1];
        prav[a[i]]=i;
        if(lev[a[i]]==-1)
            lev[a[i]]=i;
    }
    if(!kq)
    {
        cout << "NO";
        return 0;
    }
    bool f=true;
    build(0, 0, n);
    for(int i=1;i<=q;i++)
    {
        if(lev[i]!=-1 && get(0, 0, n, lev[i], prav[i]+1)<i)
            f=false;
    }
    if(f)
    {
        cout << "YES" << endl;
        for(int i=0;i<n;i++)
            cout << a[i] << ' ';
    }
    else cout << "NO";
    return 0;
}