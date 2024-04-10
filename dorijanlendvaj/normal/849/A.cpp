#include <bits/stdc++.h>

using namespace std;

int n,h[101];
bool dp[101][101];
bool bio[101][101];

bool rek(int p,int nu)
{
	if (bio[p][nu]) return dp[p][nu];
	bio[p][nu]=true;
    if (p==n && nu%2==1) return dp[p][nu]=true;
    if (p>n) return dp[p][nu]=0;
    if (h[p]%2==0) return dp[p][nu]=0;
    bool r=false;
    for (int i=p;i<n;i+=2) if (h[i]%2==1) r|=rek(i+1,nu+1);
    return dp[p][nu]=r;
}

int main()
{
	//TODO make some code
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	if (rek(0,0)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}