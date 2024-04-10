#include <iostream>
using namespace std;
int v[100005],n,m,k,ap[100005];
int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        v[i];
        ap[v[i]%m]++;
    }
    for(int i=0;i<m;i++)
        if(ap[i]>=k)
        {
            cout<<"Yes\n";
            int s=0;
            for(int j=1;j<=n;j++)
            {
                if(v[j]%m==i)
                {
                    cout<<v[j]<<" ";
                    s++;
                }
                if(s==k)
                    break;
            }
            return 0;
        }
    cout<<"No";
    return 0;
}