#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;


int n,z;
int a[maxn];

int main(){
	cin>>n>>z;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int rp=(n+2)/2,ep=rp,ans=0;
	for(int i=1;i<ep;i++){
		while(a[rp]-a[i]<z&&rp<=n) rp++;
		if(rp<=n){
			rp++;ans++;
		}
	}
	cout<<ans;
    return 0;
}