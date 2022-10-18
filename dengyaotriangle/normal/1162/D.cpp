#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxm=200005;

int n,m;
int vld[maxn],vc;
int cl[maxm*2],cr[maxm*2];
map<long long,bool> mp;
int c2=0;

long long hs(int l,int r){
	return (long long)(l+10)*(long long)(n+n+10)+r;
}
int main(){
	cin>>n>>m;
	c2=m;
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		cl[i]=l;cr[i]=r;
		mp[hs(l,r)]=1;
		mp[hs(r,l)]=1;
		cl[++c2]=r;
		cr[c2]=l;
	}
	m=c2;
	for(int i=1;i*i<=n;i++){
		if(n%i) continue;
		vld[++vc]=i;
		if(i!=1)vld[++vc]=n/i;
	}
	for(int i=1;i<=vc;i++){
		bool ok=1;
		for(int j=1;j<=m;j++){
			int l=cl[j],r=cr[j];
			if(!mp[hs((l+vld[i]-1+n)%n+1,(r+vld[i]-1+n)%n+1)]){
				ok=0;
				break;
			}
		}
		if(ok){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}