#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,m,a[N],b[N],p,phi,nb;
vector<int> d,v;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%p)
        if(y&i)
            ans=ans*x%p;
    return ans;
}int inv(int k){return gsc(k,p-2);}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int ln(int k){
	for(int i=0;i<d.size();i++)if(gsc(k,d[i])==1)return d.size()-i-1;
}
void solve(){
	cin>>n>>m>>p;phi=p-1,nb=phi;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i],nb=gcd(nb,b[i]);
	for(int i=1;i<=n;i++)a[i]=gsc(a[i],nb);
	for(int i=1;i*i<=phi;i++)if(phi%i==0){
		d.push_back(i);if(phi/i!=i)d.push_back(phi/i);
	}sort(d.begin(),d.end());
	v.resize(d.size());
	for(int i=1;i<=n;i++)v[ln(a[i])]=1;
	int ans=0;
	for(int i=0;i<d.size();i++)for(int j=i+1;j<d.size();j++)if(d[j]%d[i]==0)v[j]|=v[i];
	for(int i=0;i<d.size();i++){
		ans+=phi/d[i]*v[i];
		for(int j=i+1;j<d.size();j++)if(d[j]%d[i]==0)v[j]-=v[i];
	}cout<<ans<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}