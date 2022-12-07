#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=0, inf=1e9;
    cin>>n>>k;
    vector <int> av;
    int ar[n], la[n];
    for(int a=0; a<n; a++) la[a]=-1;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar[a]--;
        la[ar[a]]=a;
    }
    for(int a=0; a<n; a++)
    {
        int x=ar[a], fo=0;
        for(int b=0; b<av.size(); b++) if(av[b]==x) fo=1;
        if(fo==0)
        {
            an++;
            if(av.size()==k)
            {
                int be=0, bnu;
                for(int b=0; b<k; b++)
                {
                    int cu=inf;
                    for(int c=a+1; c<n; c++)
                    {
                        if(ar[c]==av[b])
                        {
                            cu=c;
                            break;
                        }
                    }
                    if(cu>be)
                    {
                        be=cu, bnu=b;
                    }
                }
                av.erase(av.begin()+bnu);
            }
            av.push_back(x);
        }
    }
    cout<<an;
}