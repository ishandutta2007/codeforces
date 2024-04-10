#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000+5;

int n,k,q;
int s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        s[l]++;
        s[r+1]--;
    }
    int sum=0;
    for(int i=1;i<N;i++)
    {
        sum+=s[i];
        if(sum>=k)
        {
            s[i]=1;
        }
        else
        {
            s[i]=0;
        }
        s[i]+=s[i-1];
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<"\n";
    }
    return 0;
}
/**

**/