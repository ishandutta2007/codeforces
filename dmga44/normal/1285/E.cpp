#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 1000005

map<int,int> m;
int li[MAXN],ls[MAXN],cc[MAXN];
int abi[MAXN],st[4*MAXN],ac[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

void update(int p,int l,int r,int L,int R,int v)
{
    if(L<=l && r<=R)
    {
        st[p]=v;
        return ;
    }
    if(l>R || L>r)
        return ;
    int mid=(l+r)>>1;

    update(p<<1,l,mid,L,R,v);
    update((p<<1)+1,mid+1,r,L,R,v);
}

int query(int p,int l,int r,int x)
{
    if(st[p])
        return st[p];
    int mid=(l+r)>>1;

    if(x>mid)
        return query((p<<1)+1,mid+1,r,x);
    else
        return query(p<<1,l,mid,x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            cin >> li[i] >> ls[i];
            s.insert(li[i]);
            s.insert(ls[i]);
        }

        int cont=1;
        for(auto y : s)
        {
            m[y]=cont;
            cont++;
        }

        for(int i=0;i<n;i++)
        {
            update(2*m[li[i]]-1,1);
            update(2*m[ls[i]],-1);

            update(1,0,2*cont-1,2*m[li[i]]-1,2*m[ls[i]]-1,i+1);
        }

        for(int i=1;i<2*cont-2;i++)
            cc[i]=query(i);

        int res=1,ok=0;
        for(int i=1;i<2*cont-2;i++)
        {
//            db(cc[i])
            if(cc[i]==0)
                res++;
            if(cc[i]==1 && i%2==0 && cc[i-1]>1 && cc[i+1]>1)
            {
                ac[query(1,0,2*cont-1,i)-1]++;
//                db(query(1,0,2*cont-1,i))
//                db("")
            }
            if(cc[i]>1)
                ok=1;
        }

        int ko=res;
        for(int i=0;i<n;i++)
        {
            res=max(res,ko+ac[i]);
//            db(ac[i])
        }
        if(ok)
            db(res)
        else
            db(n-1)
//        db("")

        for(int i=0;i<n;i++)
        {
            update(2*m[li[i]]-1,-1);
            update(2*m[ls[i]],1);
            ac[i]=0;
        }

        for(int i=0;i<=8*cont;i++)
            st[i]=0;
        m.clear();
    }

    return 0;
}
/**
1
5
1 10
1 2
3 4
5 6
7 8
**/