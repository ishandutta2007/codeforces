#include <bits/stdc++.h>

using namespace std;

int n,operacije;
int h[1001];
int pov[1001][1001];
int dp[1001],prs[1001];
long long rj;
const int MOD=1000000007;

int povrh(int a,int b)
{
    ++operacije;
    if (a<b) return pov[a][b]=0;
    if (b==0) return pov[a][b]=1;
    if (pov[a][b]) return pov[a][b];
    pov[a][b]=(povrh(a-1,b)+povrh(a-1,b-1))%MOD;
    return pov[a][b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	rj=1;
	for (int i=0;i<n;++i)
	{
	    cin>>h[i];
	    prs[i]=h[i];
	    if (i)
        {
            prs[i]+=prs[i-1];
            rj*=povrh(prs[i]-1,h[i]-1);
            //cout<<povrh(prs[i]-1,h[i]-1)<<' '<<prs[i]-1<<' '<<h[i]-1<<endl;
            rj%=MOD;
        }
	}
	cout<<rj<<endl/*<<operacije<<endl*/;
}