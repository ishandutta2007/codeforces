#include<bits/stdc++.h>

using namespace std;

const int maxn=5005;

int n,k;
double x[maxn];
double pref[maxn];
double ans=0;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		pref[i]=pref[i-1]+x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i+1<k) continue;
			double bs=pref[j]-pref[i-1];
			ans=max(ans,bs/(j-i+1));
		}
	}
	printf("%.15lf",ans);
	return 0;
}