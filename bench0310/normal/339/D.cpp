#include <iostream>

using namespace std;
const int N=(1<<17);

int n;
int a[N+1];
int tree[N+1];

void build(int idx,int l,int r,int d)
{
    if(l==r) tree[idx]=a[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m,d+1);
        build(2*idx+1,m+1,r,d+1);
        if((n+1-d)&1) tree[idx]=tree[2*idx]|tree[2*idx+1];
        else tree[idx]=tree[2*idx]^tree[2*idx+1];
    }
}

void update(int idx,int l,int r,int pos,int val,int d)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val,d+1);
        else update(2*idx+1,m+1,r,pos,val,d+1);
        if((n+1-d)&1) tree[idx]=tree[2*idx]|tree[2*idx+1];
        else tree[idx]=tree[2*idx]^tree[2*idx+1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m;
    cin >> n >> m;
    for(int i=1;i<=(1<<n);i++) cin >> a[i];
    build(1,1,(1<<n),1);
    for(int i=0;i<m;i++)
    {
        int p,b;
        cin >> p >> b;
        update(1,1,(1<<n),p,b,1);
        cout << tree[1] << endl;
    }
    return 0;
}