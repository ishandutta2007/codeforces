#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <complex>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;
 
char str[100005];

typedef struct tree * PTree;

struct tree {
    tree(int _l = 0,int _r = 0) : l(_l), r(_r), left(NULL), right(NULL) {
        memset(cnt,0,sizeof(cnt));
        pl=pr=-1;
    };
    int l,r,cnt[26],pl,pr;
    tree * left, * right;
};

PTree build(int l,int r) {
    if (l==r) {
        PTree A= new tree(l,r);
        A->cnt[str[l]-'a']++;
        return A;
    }
    int m=(l+r)>>1;
    PTree left=build(l,m),right=build(m+1,r),A=new tree(l,r);
    A->left=left; A->right=right;
    for(int i=0;i<26;++i)
        A->cnt[i]=A->left->cnt[i]+A->right->cnt[i];
    return A;
}

int tot[26]={0};
 
void push(PTree root) {
    if (root&&root->pl!=-1) {
        if (root->left) {
            memcpy(root->left->cnt,root->cnt,sizeof(root->cnt));
            root->left->pl=root->pl;
            root->left->pr=root->pr;
        }
        if (root->right) {
            memcpy(root->right->cnt,root->cnt,sizeof(root->cnt));
            root->right->pl=root->pl;
            root->right->pr=root->pr;
        }
        int mid=-1,tmp[26]={0};
        for(int i=0;i<26;++i)
            if (root->cnt[i]&1) mid=i;
        if (mid!=-1) {
            root->cnt[mid]--;
            if ((root->pl+root->pr)>=2*root->l&&(root->pl+root->pr)<=2*root->r) tmp[mid]++;
        }
        int LL=root->pl,RR=root->pr;
        for(int i=0;i<26;++i) {
            int d=root->cnt[i]/2,add;
            add=min(RR,root->r)-max(root->l,RR-d+1)+1;
            if (add>0) tmp[i]+=add;
            add=min(LL+d-1,root->r)-max(root->l,LL)+1;
            if (add>0) tmp[i]+=add;
            LL+=d; RR-=d;
        }
        root->pl=root->pr=-1;
        memcpy(root->cnt,tmp,sizeof(tmp));
    }
}

void get(PTree root,int l,int r) {
    push(root);
    if (root->l==l&&root->r==r) {
        for(int i=0;i<26;++i)
            tot[i]+=root->cnt[i];
        return;
    }
    int m=(root->l+root->r)>>1;
    if (r<=m) get(root->left,l,r);
    else if (l>m) get(root->right,l,r);
    else {
        get(root->left,l,m);
        get(root->right,m+1,r);
    }
}

void update(PTree root,int l,int r,int L,int R) {
    push(root);
    if (root->l==l&&root->r==r) {
        root->pl=L; root->pr=R;
        memcpy(root->cnt,tot,sizeof(tot));
        return;
    }
    int m=(root->l+root->r)/2;
    if (r<=m) update(root->left,l,r,L,R);
    else if (l>m) update(root->right,l,r,L,R);
    else {
        update(root->left,l,m,L,R);
        update(root->right,m+1,r,L,R);
    }
    push(root->left); push(root->right);
    for(int i=0;i<26;++i)
        root->cnt[i]=root->left->cnt[i]+root->right->cnt[i];
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,q,l,r;
    scanf("%d%d\n",&n,&q);
    gets(str); int len=strlen(str);
    PTree root=build(0,len-1);
    for(int i=0;i<q;++i) {
        scanf("%d%d",&l,&r); --l; --r;
        memset(tot,0,sizeof(tot));
        get(root,l,r);
        int ok=0;
        for(int i=0;i<26;++i)
            ok+=tot[i]&1;
        if (ok<2)
            update(root,l,r,l,r);
    }
    memset(tot,0,sizeof(tot));
    for(int i=0;i<len;++i) {
        get(root,i,i);
        for(int j=0;j<26;++j)
            if (tot[j]) {
                printf("%c",('a'+j));
                tot[j]=0;
            }
    }
    printf("\n");
    return 0;
}