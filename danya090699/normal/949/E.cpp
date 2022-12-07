#include <bits/stdc++.h>
using namespace std;
pair <int, int> dfs(vector <int> &ve, int l)
{
    vector <int> v1, v2;
    int add=0, mi=0, pl=0, ma=0;
    for(int a=0; a<ve.size(); a++)
    {
        int x1=ve[a], x2=ve[a];
        if(abs(ve[a])&1)
        {
            x1--, x2++, add=l;
        }
        x1/=2, x2/=2;
        if(x1!=0)
        {
            if(v1.size())
            {
                if(x1!=v1.back()) v1.push_back(x1);
            }
            else v1.push_back(x1);
        }
        if(x2!=0)
        {
            if(v2.size())
            {
                if(x2!=v2.back()) v2.push_back(x2);
            }
            else v2.push_back(x2);
        }
    }
    pair <int, int> an1{0, 0}, an2{0, 0};
    if(v1.size()==0)
    {
        an1.first+=add;
        return an1;
    }
    else if(v2.size()==0)
    {
        an2.second+=add;
        return an2;
    }
    else
    {
        an1=dfs(v1, l*2), an2=dfs(v2, l*2);
    }
    an1.first+=add, an2.second+=add;
    if(__builtin_popcount(an1.first)+__builtin_popcount(an1.second)<__builtin_popcount(an2.first)+__builtin_popcount(an2.second)) return an1;
    else return an2;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> ve;
    ve.resize(n);
    for(int a=0; a<n; a++) scanf("%d", &ve[a]);
    sort(ve.begin(), ve.end());
    pair <int, int> an=dfs(ve, 1);
    cout<<__builtin_popcount(an.first)+__builtin_popcount(an.second)<<"\n";
    for(int a=0; a<=20; a++)
    {
        if(an.first&(1<<a)) cout<<(1<<a)<<" ";
        if(an.second&(1<<a)) cout<<-(1<<a)<<" ";
    }
}