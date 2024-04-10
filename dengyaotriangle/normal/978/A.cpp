#include<bits/stdc++.h>

using namespace std;

const int maxl=50;

const int maxh=1005;

int h[maxh];
int a[maxl];
bool o[maxl];

int main(){
	int n,k;
	cin>>n;
	k=n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) h[a[i]]++;
	for(int i=0;i<n;i++){
		if(h[a[i]]>1){
			o[i]=1;
			h[a[i]]--;
			k--;
		}
	}
	cout<<k<<endl;
	for(int i=0;i<n;i++) if (!o[i]) cout<<a[i]<<' ';
	return 0;
}