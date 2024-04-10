#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<LL,LL> PII;
#define MAX 400010
LL n,m,k,x[MAX];
int main()
{
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)==3)
    {
        priority_queue<PII,vector<PII> ,greater<PII> > p;
        int plu=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&x[i]);
            if(x[i]<0)p.push(make_pair(-x[i],-i)),plu=1-plu;
            else p.push(make_pair(x[i],i));
        }
        while(m--)
        {
            PII w=p.top();p.pop();
            if(plu) ///K-
            {
                w.first-=k;
                if(w.first<0)w.first*=-1,w.second*=-1,plu=1-plu;
            }
            else w.first+=k;
            p.push(w);
//            cout<<w.first<<"  "<<w.second<<endl;


        }
        while(p.size())
        {
            PII w=p.top();p.pop();
            if(w.second<0)x[w.second*-1]=w.first*-1;
            else x[w.second]=w.first;
        }
        printf("%I64d",x[1]);
        for(int i=2;i<=n;i++)
            printf(" %I64d",x[i]);puts("");
    }
    return 0;
}