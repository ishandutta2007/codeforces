#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005
#define x 450

int a[MAXN],bucket[x][5],ma[x][2],lazy[x];
int res,n;

void recalc(int b,int l,int r)
{
    bucket[b][0]=MAXN;
    bucket[b][1]=-MAXN;
    bucket[b][2]=-MAXN;
    bucket[b][3]=-MAXN;
    bucket[b][4]=0;

    vector<int> aux;
    for(int i=l;i<=r;i++)
    {
        a[i]+=lazy[b];
        bucket[b][4]=max(bucket[b][4],a[i]);
        bucket[b][0]=min(bucket[b][0],a[i]);
        bucket[b][1]=max(bucket[b][1],bucket[b][4]-2*a[i]);
        aux.push_back(bucket[b][1]);
    }

    bucket[b][4]=0;
    for(int i=r;i>=l;i--)
    {
        bucket[b][4]=max(bucket[b][4],a[i]);
        bucket[b][2]=max(bucket[b][2],bucket[b][4]-2*a[i]);
        bucket[b][3]=max(bucket[b][3],aux[i-l]+bucket[b][4]);
    }
    lazy[b]=0;
}

void marcelo()
{
    res=0;
    for(int i=0;i<(n+x);i+=x)
        ma[i/x][0]=ma[i/x][1]=0;

    for(int i=0;i<n;i+=x)
    {
        ma[i/x][0]=max(ma[i/x][0],bucket[i/x][4]+lazy[i/x]);
        ma[(i/x)+1][0]=ma[i/x][0];
    }

    for(int i=n-1;i>=0;i-=x)
    {
        ma[i/x][1]=max(ma[i/x][1],bucket[i/x][4]+lazy[i/x]);
        if(i>=x)
            ma[(i/x)-1][1]=ma[i/x][1];
    }

    for(int i=0;i<=((n-1)/x);i++)
    {
        int ml=0,mr=0;
        if(i)
            ml=ma[i-1][0];
        if(i<((n-1)/x))
            mr=ma[i+1][1];
        res=max(res,ml+mr-2*(bucket[i][0]+lazy[i]));
        res=max(res,mr+bucket[i][1]-lazy[i]);
        res=max(res,ml+bucket[i][2]-lazy[i]);
        res=max(res,bucket[i][3]);
    }

    db(res)
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);

    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    n=2*(n-1);
    for(int i=0;i<n;i++)
    {
        a[i+1]=a[i];
        if(s[i]=='(')
            a[i+1]++;
        else
            a[i+1]--;
    }
    n++;

    for(int i=0;i<n;i+=x)
    {
        if(i/x!=(n-1)/x)
            recalc(i/x,i,i+x-1);
        else
            recalc(i/x,i,n-1);
    }

    marcelo();

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if(l>r)
            swap(l,r);
        r--;
        int mul=1;
        if(s[l-1]=='(')
            mul=-1;
        swap(s[l-1],s[r]);
        if(l/x==r/x)
        {
            for(int i=l;i<=r;i++)
                a[i]+=(2*mul);
            recalc(l/x,(l/x)*x,min(((l/x)*x)+x-1,n-1));
        }
        else
        {
            for(int i=(l/x)+1;i<(r/x);i++)
                lazy[i]+=(2*mul);

            for(int i=l;i/x==l/x;i++)
                a[i]+=(2*mul);
            recalc(l/x,(l/x)*x,min(((l/x)*x)+x-1,n-1));

            for(int i=r;i/x==r/x;i--)
                a[i]+=(2*mul);
            recalc(r/x,(r/x)*x,min(((r/x)*x)+x-1,n-1));
        }
        marcelo();
    }

    return 0;
}