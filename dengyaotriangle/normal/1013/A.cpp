#include<bits/stdc++.h>

using namespace std;

const int maxn=55;

int a[maxn];
int b[maxn];
int sa,sb;
int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sa+=a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		sb+=b[i];
	}
	if(sa>=sb) cout<<"Yes";
	else cout<<"No";
	return 0;
}