#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,k;
int x[maxn];
int o[maxn];
bool ans;

void chk(int l,int r,int s,int e){
	if(l>r) return;
	//cout<<l<<r<<s<<e<<endl;
	int z;
	if(l<=k){
		if(!(x[l]>=s&&x[l]<=e)){
			ans=1;
			return;
		}else{
			z=x[l];
		}
	}else{
		z=e;
	}
	o[l]=z;
	if(l>=r) return;
	chk(l+1,z-s+l,s,z-1);
	chk(r-e+z+1,r,z+1,e);
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>x[i];
	chk(1,n,1,n);
	if(ans){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++) cout<<o[i]<<' ';
	return 0;
}