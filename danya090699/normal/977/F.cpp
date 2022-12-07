#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int pr[n], an[n], be=0, bnu;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        pr[a]=-1;
        int x, cu;
        scanf("%d", &x);
        if(ma.find(x-1)==ma.end()) an[a]=1;
        else
        {
            an[a]=an[ma[x-1]]+1, pr[a]=ma[x-1];
        }
        ma[x]=a;
        if(an[a]>be)
        {
            be=an[a], bnu=a;
        }
    }
    int cu=bnu;
    vector <int> sp;
    while(cu!=-1)
    {
        sp.push_back(cu+1), cu=pr[cu];
    }
    cout<<be<<"\n";
    reverse(sp.begin(), sp.end());
    for(int a=0; a<sp.size(); a++) printf("%d ", sp[a]);
}