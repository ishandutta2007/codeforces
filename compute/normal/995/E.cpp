#include<bits/stdc++.h>
using namespace std;
long long inv(long long x,long long n)
{
    if(x==0) return 0;
    int k=n-2;
    long long ans=1;
    while(k)
    {
        if(k&1) ans=(ans*x)%n;
        x=x*x%n;
        k>>=1;
    }
    return ans;
}
long long u,v,p;
map<int ,int> h,t;
map<int,int> preh,pret,opth,optt;
int rec;
int first=1;
void print(int x)
{
    if(opth[x]==0)
    {
        return;
    }
    print(preh[x]);
    if(first)
    {
        printf("%d",opth[x]);
        first=0;
    }
    else printf(" %d",opth[x]);
}
void bfs()
{
    queue<int> head,tail;
    head.push(u);
    tail.push(v);
    h[u]=1;
    t[v]=1;
    while(!head.empty()&&!tail.empty())
    {
        int hea=head.front(),tai=tail.front();
        head.pop();tail.pop();
        if(t.count(hea))
        {
            rec=t[hea]+h[hea]-2;
            cout<<rec<<endl;
            print(hea);
            tai=hea;
            while(optt[tai]!=0)
            {
                printf(" %d",optt[tai]);
                tai=pret[tai];
            }
            return;
        }
        for(int i=1;i<=3;i++)
        {
            int hh=hea,tt=tai;
            switch(i){
                case 1:hh=(hh+1)%p;tt=(tt+1)%p;break;
                case 2:hh=(hh+p-1)%p;tt=(tt+p-1)%p;break;
                case 3:hh=inv(hh,p);tt=inv(tt,p);
            }
            if(!h.count(hh))
            {
                h[hh]=h[hea]+1;
                preh[hh]=hea;
                opth[hh]=i;
                head.push(hh);
            }
            if(!t.count(tt))
            {
                t[tt]=t[tai]+1;
                pret[tt]=tai;
                optt[tt]=(i==3?3:(i==2?1:2));
                tail.push(tt);
            }
        }
    }
}
int main()
{
    scanf("%lld%lld%lld",&u,&v,&p);
    bfs();
    cout<<endl;
    return 0;
}