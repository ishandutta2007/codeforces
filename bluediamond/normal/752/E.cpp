#include <iostream>

using namespace std;

typedef long long ll;

const int L=(int)1e7+5;
int n,cnt;
ll sum=0;
ll ap[L];
ll bigger;
int ind=0;

inline void add(int x,ll val)
{
    if(ind<=x)
        bigger+=val;
    ap[x]+=val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>cnt;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        ap[x]++;
    }
    if(sum<cnt)
    {
        cout<<"-1\n";
        return 0;
    }
    bigger=n;
    for(int i=L-1;i>=2;i--)
    {
        add(i/2,ap[i]);
        add(i-i/2,ap[i]);
        add(i,-ap[i]);
        while(bigger-ap[ind]>=cnt)
            bigger-=ap[ind],ind++;

    }
    cout<<ind<<"\n";
    return 0;
}