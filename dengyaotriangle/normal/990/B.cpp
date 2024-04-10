#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,k;
int x[maxn];
int mk[maxn];
int lp=0;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>x[i];
	sort(x,x+n);
	for(int i=0;i<n;i++){
		int d=lower_bound(x,x+i,x[i]-k)-x;
		int f=lower_bound(x,x+i,x[i])-x;
		mk[d]++;
		mk[f]--;
	}
	int cnt=0,cc=0;
	for(int i=0;i<n;i++){
		cc+=mk[i];
		if(cc==0) cnt++;
	}
	cout<<cnt;
	return 0;
}