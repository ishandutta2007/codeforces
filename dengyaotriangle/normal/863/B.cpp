#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
int x[maxn];
int chk[maxn];
int ans=0x7FFFFFFF;

int absl(int n){
	if(n<0)  return 0-n;
	return n;
}

int main(){
	cin>>n;
	for(int i=0;i<n+n;i++) cin>>x[i];
	sort(x,x+n+n);
	int cn=n+n;
	for(int i=0;i<n+n;i++){
		for(int j=i+1;j<n+n;j++){
			int idx=0;
			for(int k=0;k<n+n;k++){
				if(k==i||k==j) continue;
				chk[idx++]=x[k];
			}
			int na=0;
			for(int k=0;k<n+n-2;k+=2){
				na+=absl(chk[k]-chk[k+1]);
			}
			ans=min(ans,na);
		}
	}
	cout<<ans;
	return 0;
}