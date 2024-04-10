#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[1000003],ans[1000003],ok;
void solve(){
	for(int i=2;i<=n;i+=2){
		vis[i]^=1;
		if(i!=2)vis[i>>1]^=1;ok^=1;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
			ans[i]^=1,
			ans[i-1]^=1;
	}
	if(ok)ans[2]^=1;
	ans[1]=1;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(ans[i])
			cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(ans[i])
			printf("%d ",i);
}
unordered_map<long long,int>mp;
long long rnd(){
	return rand()*32768ll*32768ll*32768ll+rand()*32768ll*32768ll+rand()*32768ll+rand(); 
}
bool isp[1000003];
long long hsh[1000003],vl[1000003],HSH;
int main(){
	srand(time(NULL));
	cin>>n;
	memset(isp,1,sizeof(isp));
	isp[0]=0;isp[1]=0;
	for(int i=2;i<=1000000;i++)
		if(isp[i]){
			for(int j=i+i;j<=1000000;j+=i)
				isp[j]=0;
			vl[i]=rnd();
		}
	for(int i=2;i<=n;i++){
		if(isp[i])
			for(long long j=i;j<=n;j=j*i)
				for(int k=j;k<=n;k+=j)
					hsh[k]^=vl[i];
	}
	for(int i=2;i<=n;i++)
		hsh[i]^=hsh[i-1];
	for(int i=1;i<=n;i++)
		HSH^=hsh[i];
	if(HSH==0){
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(hsh[i]==HSH){
			cout<<n-1<<endl;
			for(int j=1;j<=n;j++)
				if(j!=i)
					printf("%d ",j);
			return 0;
		}
	for(int i=1;i<=n;i++)
		mp[hsh[i]]=i;
	for(int i=1;i<=n;i++)
		if(mp[hsh[i]^HSH]){
			cout<<n-2<<endl;
			int j=mp[hsh[i]^HSH];
			for(int k=1;k<=n;k++)
				if(k!=i&&k!=j)
					printf("%d ",k);
			return 0;
		}
	solve();
}