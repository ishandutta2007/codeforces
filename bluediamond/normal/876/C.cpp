#include <iostream>
#include <vector>
using namespace std;
int n,cn,y;
vector<int>v;
int main()
{
    cin>>n;
    cn=n;
    while(cn>0)
    {
        y++;
        cn/=10;
    }
    for(int i=n-9*y;i<=n;i++)
    {
        if(i<0)
            continue;
        int s=i,ci=i;
        while(ci>0)
        {
            s+=ci%10;
            ci/=10;
        }
        if(s==n)
            v.push_back(i);
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}