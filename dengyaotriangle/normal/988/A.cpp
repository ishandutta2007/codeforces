#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n,m;
int x[maxn];
int h[maxn];
int f[maxn];

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
		h[x[i]]++;
		if(f[x[i]]==0) f[x[i]]=i+1;
	}
	int cnt=0;
	for(int i=0;i<maxn;i++){
		if(h[i]!=0) cnt++;
	}
	if(cnt<m) {
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	cnt=0;
	for(int i=0;i<maxn;i++){
		if(h[i]!=0){
			cnt++;
			cout<<f[i]<<' ';
		}
		if(cnt>=m) return 0;
	}
	return 0;
}