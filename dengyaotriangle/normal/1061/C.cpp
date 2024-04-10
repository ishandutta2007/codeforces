#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxt=1000006;

int n;
int a[maxn];
long long ans[maxn];
int psb[maxn];
int psl=0;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		psl=0;
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				if(j<=i)psb[psl++]=j;
				if(j!=a[i]/j) if(a[i]/j<=i)psb[psl++]=a[i]/j;
			}
		}
		sort(psb,psb+psl,cmp);
		for(int j=0;j<psl;j++){
			if(psb[j]==1) ans[1]++;
			else{
				ans[psb[j]]+=ans[psb[j]-1];
				ans[psb[j]]=ans[psb[j]]%1000000007ll;
			}
		}
	}
	long long anst=0;
	for(int i=1;i<=n;i++){
		anst+=ans[i];
		anst=anst%1000000007ll;
	}
	cout<<anst;
	return 0;
}