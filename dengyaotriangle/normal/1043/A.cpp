#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
int x[maxn];
int mx=0;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) mx=max(x[i],mx);
	for(int i=mx;1;i++){
		int a1=0,a2=0;
		for(int j=1;j<=n;j++){
			a1+=x[j];
			a2+=i-x[j];
		}
		if(a2>a1){
			cout<<i;
			return 0;
		}
	}
	return 0;
}