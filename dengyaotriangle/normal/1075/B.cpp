#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,m;
int a[maxn];
bool isd[maxn];
int rd[maxn];
int cnt[maxn];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n+m;i++) cin>>a[i];
	for(int i=1;i<=n+m;i++) cin>>isd[i];
	int cur=1;
	for(int i=1;i<=n+m;i++){
		if(isd[i]) rd[cur++]=a[i];
	}
	for(int i=1;i<=n+m;i++){
		if(isd[i]) continue;
		int fd=a[i];
		int cr=upper_bound(rd+1,rd+1+m,fd)-rd;
		int ans1=cr;
		int ans2=cr-1;
		int d1=rd[ans1]-fd;
		int d2=fd-rd[ans2];
		if(ans2<=0){
			cnt[ans1]++;
		}else if(ans1>m){
			cnt[ans2]++;
		}else if(d1>=d2){
			cnt[ans2]++;
		}else{
			cnt[ans1]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}