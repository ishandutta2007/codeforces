#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;

int x[maxn];
int ans=0;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	sort(x,x+n);
	int nos=0,ns=1;
	for(int i=0;i<n;i++){
		if(i>=1){
			if(x[i]==x[i-1]) ns++;
			if(x[i]>x[i-1]){
				nos+=ns;
				ns=1;
			}
		}
		if(nos!=0){
			ans++;
			nos--;
		}
	}
	cout<<ans;
	return 0;
}