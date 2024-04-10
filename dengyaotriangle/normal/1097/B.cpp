#include<bits/stdc++.h>

using namespace std;

const int maxn=16;

int n;
int a[maxn];

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<(1<<n);i++){
		int deg=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1)deg+=a[j];
			else deg-=a[j];
		}
		if((deg%360+360)%360==0){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}