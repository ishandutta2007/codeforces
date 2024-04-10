#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

long long n,m;
long long lr[maxn];
long long fd;
long long pref[maxn];

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>lr[i];
	pref[0]=0;
	pref[n]=0x7FFFFFFFFFFFFFFF;
	for(int i=1;i<n;i++) pref[i]=pref[i-1]+lr[i-1];
	int lm=0;
	while(m--){
		cin>>fd;
		for(int i=lm;i<n;i++){
			if(fd>pref[i]&&fd<=pref[i+1]){
				cout<<i+1<<' '<<fd-pref[i]<<endl;
				lm=i;
				break;
			}
		}
	}
	return 0;
}