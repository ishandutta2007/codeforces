#include <bits/stdc++.h>
using namespace std;
int gmask()
{
    int mask=0;
    for(int i=0; i<3; i++)
    {
        int bit;
        cin>>bit;
        mask=mask*2+bit;
    }
    return mask;
}
void err()
{
    cout<<"Impossible";
    exit(0);
}
int pr[8];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <pair <int, int> > an;
    int f[n], t[n], us[n];
    for(int a=0; a<n; a++) f[a]=gmask();
    for(int a=0; a<n; a++) t[a]=gmask(), us[a]=0;
    for(int a=1; a<n; a++)
    {
        if(f[a]==7)
        {
            pr[t[a]]=a, us[a]=1;
            an.push_back({0, a});
        }
    }
    for(int a=0; a<n; a++)
    {
        if(__builtin_popcount(f[a])==2 and pr[f[a]])
        {
            us[a]=1, an.push_back({pr[f[a]], a});
            int mask=(f[a]&t[a]);
            if(__builtin_popcount(mask)==1) pr[mask]=a;
        }
    }
    for(int a=0; a<n; a++)
    {
        if(__builtin_popcount(f[a])==1)
        {
            if(pr[f[a]]) an.push_back({pr[f[a]], a});
            else err();
        }
        if(__builtin_popcount(f[a])==2 and us[a]==0)
        {
            if(pr[f[a]]) an.push_back({pr[f[a]], a});
            else
            {
                vector <int> sp;
                for(int i=0; i<3; i++) if(f[a]&(1<<i)) sp.push_back(1<<i);
                if(pr[sp[0]] and pr[sp[1]])
                {
                    an.push_back({pr[sp[0]], a});
                    an.push_back({pr[sp[1]], a});
                    pr[f[a]]=a;
                }
                else err();
            }
        }
    }
    cout<<"Possible\n";
    for(int a=0; a<n; a++) cout<<us[a]<<" ";
    cout<<"\n"<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first+1<<" "<<an[a].second+1<<"\n";
}