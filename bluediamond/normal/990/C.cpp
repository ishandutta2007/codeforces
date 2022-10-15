#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=310000;
int n;
struct info
{
    int sum,mi;
};
info v[N+5];

vector<int>sm[2*N+5];

int l[2*N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        v[i].mi=(1<<30);
        string a;
        cin>>a;
        int l=a.size();
        for(int j=0;j<l;j++)
        {
            if(a[j]=='(')
                v[i].sum++;
            else
                v[i].sum--;
            v[i].mi=min(v[i].mi,v[i].sum);
        }
    }
    for(int i=1;i<=n;i++)
    {
        sm[v[i].sum+N].push_back(-v[i].mi);
        l[v[i].sum+N]++;
    }
    for(int i=1;i<=2*N;i++)
    {
        sort(sm[i].begin(),sm[i].end());
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].mi<0)
            continue;
        int sum=v[i].sum;
        if(sum<0)
            continue;
        int inv=-sum;
        int ct_inv=inv+N;
        if(l[ct_inv]==0)
            continue;
        if(sm[ct_inv][0]>sum)
            continue;
        int st=0,dr=l[ct_inv]-1;
        int lst=-1;
        while(st<=dr)
        {
            int med=(st+dr)/2;
            if(sum>=sm[ct_inv][med])
            {
                st=med+1;
                lst=med;
            }
            else
            {
                dr=med-1;
            }
        }
        lst++;
        ans+=(ll)lst;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

2
((
)))(()

**/