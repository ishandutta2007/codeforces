#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int maxn=100100;

set<int>* merge(set<int> *a,set<int> *b)
{
    if(a->size()<b->size())swap(a,b);
    a->insert(b->begin(),b->end());
    delete b;
    return a;
}

struct node
{
    node* nex[27],*pre;
    int l,id,cnt;
    vector<node*> ch;
    node()
    {
        memset(nex,0,sizeof(nex));
        pre=NULL,l=0,id=-1;
    }
    set<int>* dfs()
    {
        set<int> *s=new set<int>();
        if(id!=-1)s->insert(id);
        for(int i=0;i<ch.size();i++)
            s=merge(s,ch[i]->dfs());
        cnt=s->size();
        return s;
    }
}ndl[maxn*4],*ns=ndl,*root,*last;

void extend(int c,int id=-1)
{
    node *p=last,*np=ns++;
    np->l=p->l+1;
    np->id=id;
    for(;p&&!p->nex[c];p->nex[c]=np,p=p->pre);
    if(!p)
        np->pre=root;
    else
    {
        node *q=p->nex[c];
        if(q->l==p->l+1)np->pre=q;
        else
        {
            node *nq=ns++;
            memcpy(nq->nex,q->nex,sizeof(q->nex));
            nq->l=p->l+1;
            nq->pre=q->pre;
            q->pre=np->pre=nq;
            for(;p&&p->nex[c]==q;p=p->pre)
                p->nex[c]=nq;
        }
    }
    last=np;
}

int n,k;
string str[maxn];

void init()
{
    root=last=ns++;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        for(int j=0;j<str[i].size();j++)extend(str[i][j]-'a',i);
        extend(26);
    }
    for(node *i=ndl;i!=ns;i++)
        if(i->pre)i->pre->ch.push_back(i);
}

void work()
{
    long long ans;
    for(int i=0,j,t,c;i<n;i++)
    {
        string &s=str[i];
        t=0;ans=0;
        node *x=root;
        for(j=0;j<s.size();j++)
        {
            c=s[j]-'a';
            for(;x&&!x->nex[c];x=x->pre,t=x?x->l:t);
            if(x)x=x->nex[c],t++;
            else x=root,t=0;
            while(x&&x->cnt<k)
                x=x->pre,t=x?x->l:0;
            ans+=t;
        }
        cout<<ans<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    root->dfs();
    work();
    return 0;
}