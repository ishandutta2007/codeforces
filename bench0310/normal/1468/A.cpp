#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    int val;
    Node *l=nullptr,*r=nullptr;
    Node(int nval){val=nval;}
    Node(Node *nl,Node *nr){l=nl;r=nr;val=max(l->val,r->val);}
};

Node* build(int l,int r)
{
    if(l==r) return new Node(0);
    int m=(l+r)/2;
    return new Node(build(l,m),build(m+1,r));
}

Node* update(Node *now,int l,int r,int pos,int val)
{
    if(l==r) return new Node(val);
    int m=(l+r)/2;
    if(pos<=m) return new Node(update(now->l,l,m,pos,val),now->r);
    else return new Node(now->l,update(now->r,m+1,r,pos,val));
}

int query(Node *now,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return (now->val);
    int m=(l+r)/2;
    return max(query(now->l,l,m,ql,min(qr,m)),query(now->r,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<Node*> st(n+1,nullptr);
        st[0]=build(1,n);
        stack<array<int,2>> s;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            while(!s.empty()&&s.top()[0]<=a) s.pop();
            int r=query(st[i-1],1,n,1,a)+1;
            if(!s.empty()) r=max(r,query(st[s.top()[1]-1],1,n,1,a)+2);
            s.push({a,i});
            st[i]=update(st[i-1],1,n,a,r);
        }
        cout << query(st[n],1,n,1,n) << "\n";
    }
    return 0;
}