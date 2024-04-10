#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an[n+1];
    set <int> se;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        an[a+1]=0;
        if(ar[a]!=0)
        {
            int d=1, x=1;
            if(ar[a]<0) d=-1;
            ar[a]=abs(ar[a]);
            for(int b=2; b*b<=ar[a]; b++)
            {
                if(ar[a]%b==0)
                {
                    int ch=0;
                    while(ar[a]%b==0)
                    {
                        ar[a]/=b, ch^=1;
                    }
                    if(ch) x*=b;
                }
            }
            ar[a]=x*ar[a]*d;
        }
        se.insert(ar[a]);
    }
    vector <int> ve;
    for(auto it=se.begin(); it!=se.end(); it++) ve.push_back(*it);
    int p[n], us[n];
    for(int a=0; a<n; a++) p[a]=lower_bound(ve.begin(), ve.end(), ar[a])-ve.begin();
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) us[b]=0;
        int nq=0, q=0;
        for(int b=a; b<n; b++)
        {
            if(ar[b]==0)
            {
                if(q==0) nq=1;
            }
            else
            {
                if(us[p[b]]==0) q++;
                us[p[b]]=1;
                nq=0;
            }
            an[q+nq]++;
        }
    }
    for(int a=1; a<=n; a++) cout<<an[a]<<" ";
}