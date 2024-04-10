#include<bits/stdc++.h>

using namespace std;

const int maxn=205;

int n;
int x[maxn];

int main(){
	cin>>n;
	for(int i=0;i<n+n;i++) cin>>x[i];
	sort(x,x+n+n);
	for(int i=0;i<n;i++){
		for(int j=n;j<n+n;j++){
			if(x[i]>=x[j]){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}