#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int l[maxn];
int r[maxn];
int n;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",l+i);
		r[i] = i-l[i];
	}
	r[n] = n+1;
	for (int i=n-1;i>=0;i--){
		r[i] = min(r[i],r[i+1]);
	}
	int ans =0;
	for (int i=0;i<n;i++){
		//cout<<r[i+1]<<endl;
		if(i<r[i+1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}