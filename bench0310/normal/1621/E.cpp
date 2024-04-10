#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M=400005;
vector<int> tree(4*M,0);
vector<int> lazy(4*M,0);

void apply(int idx,int x){tree[idx]+=x;lazy[idx]+=x;}
void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

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
        vector<array<ll,5>> e;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            e.push_back({a,1,1,0,i});
        }
        vector<int> teacher_id(n+1,0);
        vector<int> group_id(m+1,0);
        vector<vector<int>> student_id(m+1);
        vector<int> k(m+1,0);
        for(int i=1;i<=m;i++)
        {
            cin >> k[i];
            student_id[i].assign(k[i]+1,0);
            vector<int> b(k[i]+1,0);
            ll sum=0;
            for(int j=1;j<=k[i];j++)
            {
                cin >> b[j];
                sum+=b[j];
            }
            e.push_back({sum,k[i],-1,i,0});
            for(int j=1;j<=k[i];j++) e.push_back({sum-b[j],k[i]-1,-1,i,j});
        }
        auto cmp=[&](const auto &a,const auto &b)->bool
        {
            ll l=a[0]*b[1];
            ll r=b[0]*a[1];
            if(l!=r) return (l<r);
            else return (a[2]<b[2]);
        };
        ranges::sort(e,cmp);
        int N=e.size();
        for(int i=0;i<N;i++)
        {
            int id=i+1;
            int x=e[i][3],y=e[i][4];
            if(x==0)
            {
                update(1,1,N,1,id,1);
                teacher_id[y]=id;
            }
            else
            {
                if(y==0)
                {
                    update(1,1,N,1,id,-1);
                    group_id[x]=id;
                }
                else student_id[x][y]=id;
            }
        }
        for(int i=1;i<=m;i++)
        {
            update(1,1,N,1,group_id[i],1);
            for(int j=1;j<=k[i];j++)
            {
                update(1,1,N,1,student_id[i][j],-1);
                cout << (tree[1]>=0);
                update(1,1,N,1,student_id[i][j],1);
            }
            update(1,1,N,1,group_id[i],-1);
        }
        cout << "\n";
        for(int i=1;i<=n;i++) update(1,1,N,1,teacher_id[i],-1);
        for(int i=1;i<=m;i++) update(1,1,N,1,group_id[i],1);
    }
    return 0;
}