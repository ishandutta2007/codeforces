#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=10000;
int dp[6][sz+1];
bool us[6][sz+1];
int f(int q, int l)
{
    if(us[q][l]==0)
    {
        if(q==0) dp[q][l]=0;
        else
        {
            for(int a=0; a<l; a++) dp[q][l]+=f(q-1, min(l+dp[q][l], sz))+1;
            dp[q][l]+=f(q-1, min(l+dp[q][l], sz));
        }
    }
    us[q][l]=1;
    return dp[q][l];
}
main()
{
    int q=5, l=1;
    while(1)
    {
        int k=min(l, sz), gr=l;
        cout<<k<<" ";
        vector <int> sp;
        sp.push_back(gr);
        for(int a=0; a<k; a++)
        {
            int ne=gr+f(q-1, min(gr, sz));
            printf("%lld ", ne);
            gr=ne+1, sp.push_back(gr);
        }
        printf("\n");
        int re;
        cin>>re;
        if(re==-1) break;
        l=sp[re], q--;
    }
}