#include<bits/stdc++.h>
using namespace std;

struct node{
    node *nxt[27],*lnk;
    int len,right[3];
    node(){
        len=0;
        memset(right,0,sizeof(right));
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
    vector<node*> nds;
    SAM(){
        nds.emplace_back(getnode());
        init=last=nds.back();
    }
    void append(char c,int pos){
        c-='a';
        nds.emplace_back(getnode());
        node *cur=nds.back();
        cur->len=last->len+1;
        if(pos)cur->right[pos-1]=1;
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
                memcpy(nq->nxt,q->nxt,sizeof(node*)*27);
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
        for(int i=nds.size()-1;i>0;i--)for(int j=0;j<3;j++)nds[i]->lnk->right[j]+=nds[i]->right[j];
    }
};

typedef long long ll;
const int mod=1e9+7;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    SAM A;
    int len=2,mn=1e9;
    for(int i=1;i<=3;i++){
        cin>>s;
        len+=s.size();
        mn=min(mn,(int)s.size());
        if(i>1)A.append('z'+1,0);
        for(char c:s)A.append(c,i);
    }
    A.get_right(len);
    vector<ll> ans(len+5);
    for(node *p:A.nds){
        int l=p->lnk==nullptr?1:p->lnk->len+1,r=p->len,v=(ll)p->right[0]*p->right[1]*p->right[2]%mod;
        ans[l]+=v;
        ans[r+1]+=mod-v;
    }
    for(int i=1;i<=mn;i++){
        ans[i]=(ans[i-1]+ans[i])%mod;
        cout<<ans[i]<<' ';
    }

    return 0;
}