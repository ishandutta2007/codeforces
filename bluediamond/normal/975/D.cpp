#include <bits/stdc++.h>

using namespace std;

int n,a,b;
long long sol=0;
map<long long,long long>ap;
map<pair<int,int>,int>pararele;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        long long foo,foo_2,foo_3;
        cin>>foo>>foo_2>>foo_3;
        long long ct=a*foo_2-foo_3;
        sol+=ap[ct]-pararele[{foo_2,foo_3}];
        ap[ct]++;
        pararele[{foo_2,foo_3}]++;
    }
    sol+=sol;
    cout<<sol;
    return 0;
}