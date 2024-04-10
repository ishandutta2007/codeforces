#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n], l[q+1], r[q+1];
    set <int> se;
    for(int a=1; a<=q; a++)
    {
        l[a]=inf, r[a]=-inf;
    }
    for(int a=0; a<n; a++)
    {
        se.insert(a);
        scanf("%d", &ar[a]);
        if(ar[a])
        {
            l[ar[a]]=min(l[ar[a]], a);
            r[ar[a]]=max(r[ar[a]], a);
        }
    }
    bool ok=1, fo=0;
    for(int a=q; a>0; a--)
    {
        if(l[a]!=inf)
        {
            fo=1;
            auto it=se.lower_bound(l[a]);
            vector <set <int>::iterator> sp;
            for(it; it!=se.end(); it++)
            {
                sp.push_back(it);
                int p=(*it);
                if(p==r[a]) break;

                if(ar[p]==0) ar[p]=a;
                if(ar[p]!=a)
                {
                    ok=0;
                    break;
                }
            }
            if(ok==0) break;
            while(sp.size())
            {
                se.erase(sp.back());
                sp.pop_back();
            }
        }
        else
        {
            if(fo==0)
            {
                for(int b=0; b<n; b++)
                {
                    if(ar[b]==0)
                    {
                        ar[b]=a, se.erase(b);
                        fo=1;
                        break;
                    }
                }
                if(fo==0)
                {
                    ok=0;
                    break;
                }
            }
        }
    }
    if(ok)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++)
        {
            if(ar[a]==0) ar[a]=1;
            printf("%d ", ar[a]);
        }
    }
    else cout<<"NO";
}