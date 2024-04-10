#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
long long x[maxn];
long long bf=0;

int main(){
	cin>>n;
	memset(x,-1,sizeof(x));
	for(int i=2;i<=n;i+=2){
		bool ok=0;
		cin>>x[i];
		for(int j=1;j*j<=x[i];j++){
			if(x[i]%j) continue;
			long long c=x[i]/j,d=j;
			long long a=c+d,b=c-d;
			if((a&1)||(b&1)) continue;
			long long ca=a/2,cb=b/2;
			long long b2=cb*cb;
			if(b2-bf<=0) continue;
			if(x[i-1]==-1||x[i-1]>b2-bf)x[i-1]=b2-bf;
			ok=1;
		}
		if(!ok){
			cout<<"No";
			return 0;
		}
		bf+=x[i-1]+x[i];
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++) cout<<x[i]<<' ';
	return 0;
}