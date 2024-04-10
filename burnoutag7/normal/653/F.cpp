#include<bits/stdc++.h>
using namespace std;

struct node{
    node *nxt[2],*lnk;
    int len,right;
    node(){
        len=right=0;
        lnk=nullptr;
        memset(nxt,0,sizeof(nxt));
    }
};

node *pool;
int poolsz;

node* getnode(){
    if(poolsz==0)pool=new node[poolsz=12306];
    poolsz--;
    return pool++;
}

struct SAM{
    node *init,*last;
    int tot;
    vector<node*> nds;
    SAM(){
        nds.emplace_back(getnode());
        init=last=nds.back();
        tot=0;
    }
    void append(char c){
        c-='(';
        nds.emplace_back(getnode());
        node *cur=nds.back();
        cur->len=last->len+1;
        cur->right=++tot;
        node *p=last;
        while(p!=nullptr&&p->nxt[c]==nullptr){
            p->nxt[c]=cur;
            p=p->lnk;
        }
        if(p==nullptr){
            cur->lnk=init;
        }else{
            node *q=p->nxt[c];
            if(p->len+1==q->len){
                cur->lnk=q;
            }else{
                nds.emplace_back(getnode());
                node *nq=nds.back();
                nq->lnk=q->lnk;
                memcpy(nq->nxt,q->nxt,sizeof(node*)*2);
                nq->len=p->len+1;
                while(p!=nullptr&&p->nxt[c]==q){
                    p->nxt[c]=nq;
                    p=p->lnk;
                }
                q->lnk=cur->lnk=nq;
            }
        }
        last=cur;
    }
    void get_right(int len){
        vector<int> cnt(len+1);
        vector<node*> nn(nds.size());
        for(node *p:nds)cnt[p->len]++;
        for(int i=1;i<=len;i++)cnt[i]+=cnt[i-1];
        for(node *p:nds)nn[--cnt[p->len]]=p;
        swap(nn,nds);
        for(int i=nds.size()-1;i>0;i--)nds[i]->lnk->right=nds[i]->right;
    }
};

int n,h[500005],lb[500005];
char s[500005];
vector<pair<int,int>> q[500005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s+1;
    SAM A;
    stack<int> st;
    st.emplace(0);
    h[0]=-1e9;
    map<int,vector<int>> mp;
    mp[0].emplace_back(0);
    for(int i=1;i<=n;i++){
        A.append(s[i]);
        h[i]=(i!=1?h[i-1]:0)+(s[i]=='(')-(s[i]==')');
        while(h[st.top()]>=h[i]){
            st.pop();
        }
        lb[i]=i-st.top();
        st.emplace(i);
        mp[h[i]].emplace_back(i);
    }
    A.get_right(n);
    for(node *p:A.nds){
        if(p->len)q[p->right].emplace_back(p->lnk->len+1,min(lb[p->right],p->len));
    }
    long long ans=0;
    for(int cp=1;cp<=n;cp++){
        vector<int> &ch=mp[h[cp]];
        for(pair<int,int> &p:q[cp]){
            int l=cp-p.second,r=cp-p.first;
            ans+=max(0,int(upper_bound(ch.begin(),ch.end(),r)-lower_bound(ch.begin(),ch.end(),l)));
        }
    }
    cout<<ans;

    return 0;
}