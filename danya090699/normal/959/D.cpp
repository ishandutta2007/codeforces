#include <bits/stdc++.h>
using namespace std;
const int sz=2e6;
bool us[sz];
set <int> se;
void del2(int x)
{
    for(int a=x; a<sz; a+=x)
    {
        if(us[a])
        {
            us[a]=0, se.erase(a);
        }
    }
}
void del(int x)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            del2(a);
            while(x%a==0) x/=a;
        }
    }
    if(x>1) del2(x);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, fo=0;
    cin>>n;
    for(int a=2; a<sz; a++)
    {
        se.insert(a), us[a]=1;
    }
    for(int a=0; a<n; a++)
    {
        int x, va;
        cin>>x;
        if(fo==0)
        {
            if(se.find(x)!=se.end()) va=x;
            else
            {
                va=*se.upper_bound(x), fo=1;
            }
        }
        else va=*se.begin();
        cout<<va<<" ";
        del(va);
    }
}