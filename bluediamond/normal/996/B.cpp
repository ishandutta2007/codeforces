#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000;

int n,v[N+5];
int mi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    mi=v[0];
    for(int i=1;i<n;i++)
        mi=min(mi,v[i]);
    int poz=0+mi%n;
    while(1)
    {
        if(v[poz]-mi<=0)
        {
            cout<<poz+1<<"\n";
            return 0;
        }
        mi++;
        poz++;
        poz%=n;
    }
  ///  cout<<poz<<"\n";
    return 0;
}
/**

**/