#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,T,b[200003];
map<long long,long long>mp;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",b+i);
		mp.clear();
		mp[0]=1;
		long long lazy=0,all=1,del;
		for(int i=0;i<n;i++){
			del=mp[lazy];
			mp[lazy]=all;
			lazy+=b[i];
			all=(all*2-del+mod)%mod;
		}cout<<all<<endl;
	}
}