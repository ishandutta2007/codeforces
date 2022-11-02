#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define MAX 100010
LL t,x[MAX],y[MAX],DS[MAX],use[MAX],v[MAX];
LL F(LL z){ return z==DS[z]? z:DS[z]=F(DS[z]); }
void U(LL z,LL Z){ DS[F(z)]=F(Z); }
int main()
{
    while(scanf("%I64d",&t)==1)
    {
        for(int i=0;i<t;i++)scanf("%I64d",&x[i]);
        for(int i=0;i<t;i++)scanf("%I64d",&y[i]);
        for(int i=0;i<t;i++)DS[i]=i;  /// set
        memset(use,0,sizeof use);
        LL big=0;
        vector<LL> ans;
        ans.push_back(0);
        for(int i=t-1;i>=0;i--)
        {
            LL w=y[i]-1;use[w]=1;
            v[F(w)]=x[w];
            if(w-1>=0 && use[w-1]==1)
            {
                LL qq=v[F(w-1)]+v[F(w)];
                U(w,w-1);
                v[F(w)]=qq;
            }
            if(w+1<t && use[w+1]==1)
            {
                LL qq=v[F(w+1)]+v[F(w)];
                U(w,w+1);
                v[F(w)]=qq;
            }
            big=max(big,v[F(w)]);
//            cout<<big<<endl;
            ans.push_back(big);
//            int wwww;
//            cin>>wwww;
        }
        for(int i=ans.size()-2;i>=0;i--)
            printf("%I64d\n",ans[i]);

    }
    return 0;
}