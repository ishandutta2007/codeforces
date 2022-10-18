#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n;
int h[maxn];
int k;
int rh[maxn];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)rh[j]=h[j];
		sort(rh+1,rh+1+i);rh[i+1]=0;
		int cnt1=0;
		for(int j=1;j<=i;j+=2) cnt1+=max(rh[j],rh[j+1]);
		int cnt2=0;
		for(int j=i;j>=1;j-=2) cnt2+=max(rh[j],rh[j-1]);
		if(min(cnt1,cnt2)>k){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}