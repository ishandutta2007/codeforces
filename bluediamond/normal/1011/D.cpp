#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=30+5;
int lim,n;
int v[N];

int main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(0);
    cin>>lim>>n;
    for(int j=1;j<=n;j++)
    {
        cout<<"1"<<endl;
        cin>>v[j];
        if(v[j]==0)
        {
            return 0;
        }
        /// v[j] = 1 ok
        /// v[j] = -1 not ok
    }
    int r=0,pas=(1<<30);
    int cur=1;
    while(pas)
    {
        if(r+pas<=lim)
        {
            cout<<r+pas<<"\n";
            int t;
            cin>>t;
            if(t==0)
            {
                return 0;
            }
            t*=v[cur];
            if(t==1)
                r+=pas;
            cur++;
            if(cur>n)
                cur=1;
        }
        pas/=2;
    }
    return 0;
}
/**
**/