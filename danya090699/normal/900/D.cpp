#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int po(int x, int y)
{
    if(y==0) return 1;
    else
    {
        if(y%2) return (1ll*x*po(x, y-1))%mod;
        else
        {
            int x2=po(x, y/2);
            return (1ll*x2*x2)%mod;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, an=0;
    cin>>x>>y;
    vector <int> de;
    for(int a=1; a*a<=y; a++)
    {
        if(y%a==0)
        {
            de.push_back(a);
            if(a!=y/a) de.push_back(y/a);
        }
    }
    sort(de.begin(), de.end());
    int ar[de.size()];
    for(int a=de.size()-1; a>=0; a--)
    {
        int cu=de[a];
        if(cu%x==0)
        {
            ar[a]=po(2, y/cu-1);
            for(int b=a+1; b<de.size(); b++)
            {
                if(de[b]%cu==0)
                {
                    ar[a]-=ar[b];
                    if(ar[a]<0) ar[a]+=mod;
                }
            }
            if(cu==x) an=ar[a];
        }
    }
    cout<<an;
}