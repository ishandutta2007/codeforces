#include<stdio.h>
#include<map>
#include<set>
using namespace std;
int n;
map<int,int>person_coat;
set<int>coat;
struct node{
    int x;
    node *l,*r;
}*root;
struct Region{
    int pos,len;
    bool operator<(Region b)const{
        return len<b.len||(len==b.len&&pos<b.pos);
    }
};
set<Region>R;
void ins(node *&ptr,int v,int pos,int x,int y){
    ptr->x+=v;
    if(x==y)return;
    int mid=(x+y)/2;
    if(pos<=mid){
        if(ptr->l==NULL){
            ptr->l=new node;
            ptr->l->l=ptr->l->r=NULL;
            ptr->l->x=0;
        }
        ins(ptr->l,v,pos,x,mid);
    }
    else{
        if(ptr->r==NULL){
            ptr->r=new node;
            ptr->r->l=ptr->r->r=NULL;
            ptr->r->x=0;
        }
        ins(ptr->r,v,pos,mid+1,y);
    }
}
int q(node *&ptr,int x,int y,int l,int r){
    int mid=(l+r)/2;
    if(ptr==NULL)return 0;
    if(x<=l&&y>=r)return ptr->x;
    if(y<=mid)return q(ptr->l,x,y,l,mid);
    else if(x>mid)return q(ptr->r,x,y,mid+1,r);
    else return q(ptr->l,x,mid,l,mid)+q(ptr->r,mid+1,y,mid+1,r);
}
void Insert(int x){
    int y;
    set<Region>::iterator it=R.end();
    it--;
    Region tmp = *it;
    R.erase(it);
    y=tmp.pos+tmp.len/2;
    person_coat[x]=y;
    coat.insert(y);
    if(tmp.len!=1)R.insert((Region){tmp.pos,(tmp.len)/2});
    if(tmp.len>2)R.insert((Region){tmp.pos+tmp.len/2+1,(tmp.len-1)/2});
    ins(root,1,y,1,n);
}
void Delete(int x){
    int y=person_coat[x];
    person_coat[x]=0;
    set<int>::iterator it2,it1=coat.find(y);
    it2=it1;
    it1--;
    if(*it1+1!=*it2){
        R.erase((Region){*it1 + 1, *it2-*it1-1});
    }
    it1++;
    it1++;
    if(*it2+1!=*it1){
        R.erase((Region){*it2 + 1, *it1-*it2-1});
    }
    it2--;
    R.insert((Region){*it2 + 1, *it1-*it2-1});
    coat.erase(y);
    ins(root,-1,y,1,n);
}
void Q(int x,int y){
    printf("%d\n",q(root,x,y,1,n));
}
main(){
    int q,x,y;
    scanf("%d%d",&n,&q);
    root=new node;
    root->x=0;
    root->l=root->r=NULL;
    R.insert((Region){1,n});
    coat.insert(0);
    coat.insert(n+1);
    while(q--){
        scanf("%d",&x);
        if(x){
            if(person_coat.count(x)==0 || person_coat[x]==0){
                Insert(x);
            }
            else{
                Delete(x);
            }
        }
        else{
            scanf("%d%d",&x,&y);
            Q(x,y);
        }
    }
}