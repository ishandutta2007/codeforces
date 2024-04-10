#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;

struct dat{
	int d,t,i;
};

int n;
dat d[maxn];
long long t;
int ans[maxn];

bool chk(int c){
	long long tt=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt==c) break;
		if(d[i].d>=c){
			tt+=d[i].t;
			ans[++cnt]=d[i].i;
		}
	}
	if(cnt<c) return 0;
	if(tt>t) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>d[i].d>>d[i].t;
		d[i].i=i;
	}
	sort(d+1,d+1+n,[](dat a,dat b){
		return a.t<b.t;
	});
	int l=0,r=n;
	while(r-l>2){
		int m=(l+r)>>1;
		if(chk(m))l=m;
		else r=m;
	}
	for(int i=r;i>=l;i--){
		if(chk(i)){
			cout<<i<<'\n'<<i<<'\n';
			for(int j=1;j<=i;j++)cout<<ans[j]<<' ';
			return 0;
		}
	}
    return 0;
}