#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
long long x[maxn];
long long pfx[maxn];
map<long long , long long > m;
long long ans=0;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		pfx[i]=pfx[i-1]+x[i];
	}
	for(int i=0;i<=n;i++){
		m[pfx[i]]=i+1;
		//cout<<pfx[i]<<m[pfx[i]]-1<<endl;
		//cout<<m[pfx[i]];
	}
	long long csum=0;
	for(int i=n;i>=0-1;i--){
		//cout<<csum<<m[csum]<<endl;
		if(m[csum]!=0){
			if(m[csum]-2<i){
				if(csum>ans) ans=csum;
			}
		}
		if(i>=0)csum+=x[i];
	}
	cout<<ans;
	return 0;
}