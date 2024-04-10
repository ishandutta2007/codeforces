#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n;
int x[maxn];
int y[maxn];
int o[maxn];
int ol;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) y[i]=x[i]-x[i-1];
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(int j=i+1;j<=n;j++){
			if(y[j]!=y[j-i]){
				ok=0;
				break;
			}
		}
		if(ok){
			o[ol++]=i;
		}
	}
	cout<<ol<<endl;
	for(int i=0;i<ol;i++) cout<<o[i]<<' ';
	return 0;
}