#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1005;

int n;
long long a[maxn],b[maxn];
double ans;
double ini;

int main(){
	cin>>n>>ini;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<-1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==1){
			cout<<-1;
			return 0;
		}
	}
	ans=ini;
	
	for(int i=n;i>0;i--){
		if(i==n) ans=ans*((double)(b[1])/(double)(b[1]-1));
		else ans=ans*((double)(b[i+1])/(double)(b[i+1]-1));
		ans=ans*((double)(a[i])/(double)(a[i]-1));
	}
	printf("%.9lf",ans-ini);
	return 0;
}