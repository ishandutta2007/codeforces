#include <bits/stdc++.h>

using namespace std;

struct quest{
    long long l,r;
};
int H;

vector <quest> yes;
vector <quest> no,c;

long long child(long long d,long long node,bool dir)
{
    while(d<H){
        d++;
        node = node*2+dir;
    }
    
    return node;
}

bool comp(quest qa, quest qb)
{
    return qa.l < qb.l;
}

quest p(quest qa, quest qb)
{
    quest t;
    if(qa.l > qb.l) t=qa, qa=qb, qb=t;
    
    if(qa.r < qb.l) qa.r=-1, qa.l=-1;
    else if(qa.r >= qb.r) return qb;
    else qa.l = qb.l;
    
    return qa;
}

int main()
{
    int s,i;
    scanf("%d %d",&H,&s);
    
    long long d,l,r;
    int a;
    quest q;
    
    for(i=0; i<s; i++){
        scanf("%I64d %I64d %I64d %d",&d,&l,&r,&a);
        q.l = child(d,l,0);
        q.r = child(d,r,1);
        if(a) yes.push_back(q);
        else c.push_back(q);
    }
    
    sort(c.begin(),c.end(),comp);
    
    if(!c.empty()){
        no.push_back(c[0]);
        for(i=1; i<c.size(); i++){
            if(no.back().r+1 >= c[i].l){
                if(no.back().r < c[i].r) no.back().r = c[i].r;
            }
            else{
                no.push_back(c[i]);
            }  
        }
    }
    
    q.l = child(1,1,0);
    q.r = child(1,1,1);
    
    for(i=0; i<yes.size(); i++){
        q = p(q,yes[i]);
        if(q.l == -1 && q.r == -1){
            printf("Game cheated!\n");
            return 0;
        }
    }
    
    for(i=0; i<no.size(); i++){
        if(no[i].r < q.l || no[i].l > q.r) continue;
        if(no[i].l <= q.l && q.r <= no[i].r){
            printf("Game cheated!\n");
            return 0;
        }
        if(q.l < no[i].l && no[i].r < q.r){
            printf("Data not sufficient!\n");
            return 0;
        }
        if(no[i].l <= q.l && q.l <= no[i].r) q.l = no[i].r+1;
        else if(no[i].l <= q.r && q.r <= no[i].r) q.r = no[i].l-1;
    }
    
    if(q.l == q.r) printf("%I64d\n",q.l);
    else printf("Data not sufficient!\n");
    
    return 0;
}