#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int n,m;
int a[N];
int b[N];
int s[N]; 
int p[N];
void solve(){
	scanf("%d",&n);
	b[n+1]=0;
	a[n+1]=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	int l=0,r=n+1;
	for(int i=1;i<=n;i++){
		while(a[i]>b[l])l++;
		s[i]=l;
	}
	for(int i=n;i>=1;i--){
		if(b[i]<a[i+1]){
			p[i]=i;
		}
		else p[i]=p[i+1];
	}
	
	for(int i=1;i<=n;i++){
		printf("%d ",b[s[i]]-a[i]);
	}printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d ",b[p[i]]-a[i]);
	}printf("\n");
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}