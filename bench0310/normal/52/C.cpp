#include <bits/stdc++.h>

using namespace std;

const int N=200005;
long long tree[4*N];
long long lazy[4*N];

void push(int idx)
{
    tree[2*idx]+=lazy[idx];
    lazy[2*idx]+=lazy[idx];
    tree[2*idx+1]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,long long val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

long long query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return (1ll<<60);
    if(l==ql&&r==qr) return tree[idx];
    push(idx);
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

vector<int> in()
{
    vector<int> v;
    int t=0;
    int s=1;
    char c;
    while(1)
    {
        c=getchar();
        if(c=='-') s=-1;
        else if(c==' '||c=='\n')
        {
            v.push_back(s*t);
            t=0;
            s=1;
        }
        else t=(10*t+(c-'0'));
        if(c=='\n') break;
    }
    return v;
}

int main()
{
    int n=in()[0];
    vector<int> t=in();
    for(int i=1;i<=n;i++) update(1,1,n,i,i,t[i-1]);
    int q=in()[0];
    while(q--)
    {
        vector<int> x=in();
        x[0]++;
        x[1]++;
        if(x.size()==2)
        {
            int a,b;
            tie(a,b)={x[0],x[1]};
            if(a<=b) printf("%I64d\n",query(1,1,n,a,b));
            else printf("%I64d\n",min(query(1,1,n,1,b),query(1,1,n,a,n)));
        }
        else
        {
            int a,b,c;
            tie(a,b,c)={x[0],x[1],x[2]};
            if(a<=b) update(1,1,n,a,b,c);
            else
            {
                update(1,1,n,1,b,c);
                update(1,1,n,a,n,c);
            }
        }
    }
    return 0;
}