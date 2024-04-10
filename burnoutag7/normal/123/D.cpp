#include<bits/stdc++.h>
using namespace std;

struct node{
    node *nxt[26],*lnk;
    int len,right;
    node(){
        len=0;
        right=1;
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
    void append(char c){
        c-='a';
        nds.emplace_back(getnode());
        node *cur=nds.back();
        cur->len=last->len+1;
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
                nq->right=0;
                memcpy(nq->nxt,q->nxt,sizeof(node*)*26);
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
    long long get_right(int len){
        vector<int> cnt(len+1);
        vector<node*> nn(nds.size());
        for(node *p:nds)cnt[p->len]++;
        for(int i=1;i<=len;i++)cnt[i]+=cnt[i-1];
        for(node *p:nds)nn[--cnt[p->len]]=p;
        swap(nn,nds);
        for(int i=nds.size()-1;i>0;i--)nds[i]->lnk->right+=nds[i]->right;
        long long res=0;
        for(node *p:nds)res+=(long long)p->right*(p->right+1)/2*(p->lnk==nullptr?p->len:p->len-p->lnk->len);
        return res;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    SAM A;
    cin>>s;
    for(char c:s)A.append(c);
    cout<<A.get_right(s.size());

    return 0;
}