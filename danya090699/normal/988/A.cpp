#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ma[x]=a+1;
    }
    if(ma.size()>=k)
    {
        cout<<"YES\n";
        auto it=ma.begin();
        while(k)
        {
            cout<<(*it).second<<" ";
            k--, it++;
        }
    }
    else cout<<"NO";
}