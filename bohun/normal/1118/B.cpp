#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int r=0;
const int mod=1e9+7;
struct matrix
{
	int t[105][105];
	matrix()
	{
		memset(t,0,sizeof(t));
	}
	matrix operator * ( const matrix a )
	{
		matrix res;
		for(int i=1;r>=i;i++)
			for(int k=1;r>=k;k++)
				for(int j=1;r>=j;j++)
					res.t[i][j]=(res.t[i][j]+(ll)t[i][k]*a.t[k][j])%mod;
		return res;
	}
};
int n;
int t[200005];
int pref[200005][2];
int suf[200005][2];
int main(){
	cin>>n;
	for(int i=1;n>=i;i++)
		{
			cin>>t[i];
			pref[i][i%2]+=t[i];
			pref[i][i%2]+=pref[i-1][i%2];
			pref[i][(i+1)%2]+=pref[i-1][(i+1)%2];
		}
	for(int i=n;i>=1;i--)
	{
		suf[i][0]+=suf[i+1][0];
		suf[i][1]+=suf[i+1][1];
		suf[i][i%2]+=t[i];
	}
	int res=0;
	for(int i=1;n>=i;i++)
	{
		ll a=pref[i-1][0]+suf[i+1][1];
		ll b=pref[i-1][1]+suf[i+1][0];
		if(a==b)
			res++;
	}
	cout<<res;
	
	
    return 0;
}