#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int w[N];
int a[N];
int s[N];
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		int x=a[i];
		while(x){
			x>>=1;
			w[i]++;
		}
	}
	for(i=1;i<n-1;i++){
		if(w[i]==w[i+1]&&w[i]==w[i+2]){
			cout<<1;
			return 0;
		}
	}
	for(i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	int ans=1e9;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			for(k=j+1;k<=n;k++){
				if((s[j]^s[i-1])>(s[k]^s[j]))
					ans=min(ans,k-i-1);
			}
		}
	}
	if(ans==1e9) cout<<-1;
	else cout<<ans;
	return 0;
}