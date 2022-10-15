#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

const int N=1000+5;

bool p[N];

bool isp(int x)
{
    if(x<=1)
    {
        return 0;
    }
    else
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=1;i<N;i++)
    {
        p[i]=isp(i);
    }
    set<int>s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(p[i])
        {
            int j=i;
            while(j<=n)
            {
                s.insert(j);
                j*=i;
            }
        }
    }
    cout<<s.size()<<"\n";
    for(auto &it:s)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}
/**


**/