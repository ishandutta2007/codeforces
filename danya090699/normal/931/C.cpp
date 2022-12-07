#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mi=1e9, best=1e9, an[3];
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        mi=min(mi, ar[a]);
    }
    int q[3]={0, 0, 0}, su=0;
    for(int a=0; a<n; a++)
    {
        q[ar[a]-mi]++, su+=ar[a]-mi;
    }
    for(int a=0; a<=n; a++)
    {
        if(su>=n-a)
        {
            int q2=su-(n-a);
            int q1=(n-a)-q2;
            if(q1>=0)
            {
                bool ok=1;
                if(q[2]==0 and q2>0) ok=0;
                if(q[1]==0 and q[2]==0 and q1>0) ok=0;
                if(ok)
                {
                    int x=min(a, q[0])+min(q1, q[1])+min(q2, q[2]);
                    if(x<best)
                    {
                        best=x, an[0]=a, an[1]=q1, an[2]=q2;
                    }
                }
            }
        }
    }
    cout<<best<<"\n";
    for(int a=0; a<an[0]; a++) cout<<mi<<" ";
    for(int a=0; a<an[1]; a++) cout<<mi+1<<" ";
    for(int a=0; a<an[2]; a++) cout<<mi+2<<" ";
}