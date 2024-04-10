#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
int sv[1000005];
int pre[1000005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2; i<=1000000; i++){
		if(sv[i]!=0){
			continue;
		}
		for(int x=2*i; x<=1000000; x=x+i){
			if(sv[x]==0){
				sv[x]=i;
			}
		}
	}
	pre[0]=0;
	pre[1]=1;
	for(int i=2; i<=1000000; i++){
		if(sv[i]==0){
			pre[i]=pre[i-1];
			continue;
		}
		pre[i]=max(pre[i-1], i/sv[i]);
	}
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		cout<<pre[x]<<endl;
	}
	return 0;
}