#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x0,y0,ax,ay,bx,by,t,xs,xe;
vector<ll>numu,numv;
ll num[66][66];
int ans=0;
int main(){
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>xe>>t;
	numu.push_back(x0),numv.push_back(y0);
	while (1){
		x0=x0*ax+bx,y0=y0*ay+by;
		numu.push_back(x0),numv.push_back(y0);
		if (x0>=2e16 || y0>=2e16) break;
	}
	for (int i=1;i<numu.size();i++)
		num[i-1][i]=abs(numu[i]-numu[i-1])+abs(numv[i]-numv[i-1]);
	for (int k=2;k<=numu.size();k++)
		for (int i=0;i+k-1<numu.size();i++)
			num[i][i+k-1]=num[i][i+1]+num[i+1][i+k-1];
	for (int i=0;i<numu.size();i++){
		ll plt=abs(xs-numu[i])+abs(xe-numv[i]);
		plt=t-plt;
		for (int j=i;j>=0;j--) for (int k=i;k<numu.size();k++)
			if (plt>=num[j][k]+min(num[j][i],num[i][k])) ans=max(ans,k-j+1);
	}
	cout<<ans;
}