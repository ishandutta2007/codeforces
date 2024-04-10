#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;
const int LIM=1000000000;
int n;
ll v[N+5];
set<int>s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        s.insert(v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ll k=1;
        for(int j=0;j<=35;j++)
        {
            if(v[i]+k+k<=LIM && s.find(v[i]+k)!=s.end() && s.find(v[i]+k+k)!=s.end())
            {
                cout<<"3\n";
                cout<<v[i]<<" "<<v[i]+k<<" "<<v[i]+k+k<<"\n";
                return 0;
            }
            k+=k;
        }
    }
    for(int i=1;i<=n;i++)
    {
        ll k=1;
        for(int j=0;j<=35;j++)
        {
            if(v[i]+k<=LIM && s.find(v[i]+k)!=s.end())
            {
                cout<<"2\n";
                cout<<v[i]<<" "<<v[i]+k<<"\n";
                return 0;
            }
            k+=k;
        }
    }
    cout<<"1\n";
    cout<<v[1]<<"\n";
    return 0;
}
/**
**/