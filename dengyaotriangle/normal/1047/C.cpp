#include<bits/stdc++.h>
using namespace std;

const int maxn=300005;
const int maxp=4000;

int p[maxp]; 
int mp[maxp],pc[maxp];
int rp[maxp];
int n;
int maxo;
int maxo2;
map<int,int> m;

bool isP(int n){
	if(n<=1) return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(mp,0x3f,sizeof(mp));
	int cnt=0;
	for(int i=0;i<maxp;i++){
		rp[i]=-1;
		pc[i]=1;
		if(isP(i)){
			p[cnt++]=i;
			rp[i]=cnt-1;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int cur;
		cin>>cur;
		for(int j=0;j<cnt;j++){
			int cc=0;
			while(cur%p[j]==0){
				cur/=p[j];
				cc++;
			}
			if(cc<mp[j]){
				pc[j]=1;
				mp[j]=cc;
			}else if(cc==mp[j]){
				pc[j]++;
			}
		}
		if(cur>=maxp){
			m[cur]++;
			if(m[cur]>maxo) maxo=m[cur];
			else if(m[cur]>maxo2) maxo2=m[cur];
		}
	} 
	int ans=-1;
	if(maxo!=0){
		if(maxo!=n) ans=n-maxo;
		else if(maxo2!=0) ans=maxo2; 
	} 
	for(int i=0;i<cnt;i++){
		if(pc[i]!=n){
			if(pc[i]<ans||ans==-1) ans=pc[i];
		}
	}
	cout<<ans;
    return 0; 
}