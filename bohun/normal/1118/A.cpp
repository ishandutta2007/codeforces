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
int q;
ll a,b,c;
int main(){
	cin>>q;
	while(q--)
	{
		cin>>a>>b>>c;
		ll w1=(a/2)*c+b*(a%2==1);
		ll w2=a*b;
		cout<<min(w1,w2)<<endl;
	}
	
	
    return 0;
}