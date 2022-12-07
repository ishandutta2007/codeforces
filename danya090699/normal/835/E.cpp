//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y, p1=-1, p2=0;
    cin>>n>>x>>y;
    vector <int> ve[10];
    bool an[10];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<10; b++) if((a&(1<<b))>0) ve[b].push_back(a);
    }
    for(int a=0; a<10; a++)
    {
        int m=ve[a].size();
        if(m>0)
        {
            int cu;
            cout<<"? "<<m;
            for(int b=0; b<m; b++) cout<<" "<<ve[a][b]+1;
            cout<<"\n";
            cin>>cu;
            if(cu!=x*(m%2))
            {
                an[a]=1;
                if(p1==-1)
                {
                    int l=0, r=m;
                    while(r-l>1)
                    {
                        int mid=(l+r)/2, cu;
                        cout<<"? "<<mid;
                        for(int b=0; b<mid; b++) cout<<" "<<ve[a][b]+1;
                        cout<<"\n";
                        cin>>cu;
                        if(cu==x*(mid%2)) l=mid;
                        else r=mid;
                    }
                    p1=ve[a][l];
                }
            }
            else an[a]=0;
        }
        else an[a]=0;
    }
    for(int a=0; a<10; a++)
    {
        if(an[a]==0)
        {
            if((p1&(1<<a))>0) p2+=(1<<a);
        }
        else
        {
            if((p1&(1<<a))==0) p2+=(1<<a);
        }
    }
    if(p1>p2) swap(p1, p2);
    cout<<"! "<<p1+1<<" "<<p2+1;
}