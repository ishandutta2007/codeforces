#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=500000;
const int K=100;
const int P=100;

int n,k,p;
int v[N+5];

int dp[2][K+5][P+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        v[i]%=p;
    }
    k=min(k,(int)2e8/(n*p));
    for(int a=0;a<=1;a++)
        for(int b=0;b<=K;b++)
            for(int c=0;c<=P;c++)
                dp[a][b][c]=(1<<30);
    dp[1][1][v[1]]=0;
    int it=0;
    for(int poz=2;poz<=n;poz++)
    {
        for(int cnt=1;cnt<=k;cnt++)
        {
            int mi=(1<<30);
            for(int lst=0;lst<p;lst++)
            {
                int ant=lst-v[poz]+p;
                ant%=p;
                dp[it][cnt][lst]=dp[1-it][cnt][ant];
                mi=min(mi,dp[1-it][cnt-1][lst]+lst);
            }
            dp[it][cnt][v[poz]]=min(dp[it][cnt][v[poz]],mi);
        }
        it=1-it;
    }
    it=n%2;
    int bst=(1<<30);
    for(int lst=0;lst<p;lst++)
    {
        bst=min(bst,dp[it][k][lst]+lst);
    }
    cout<<bst<<"\n";
    return 0;
}