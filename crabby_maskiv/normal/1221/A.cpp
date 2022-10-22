#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3fll;
int n,m;
ll p[N],a[N];
int cnt[N];
int main(){
	int i,j;
	p[0]=1;
	for(i=1;i<=29;i++) p[i]=p[i-1]<<1;
	int T;cin>>T;
	while(T--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++){
			cin>>a[i];
			for(j=0;j<30;j++)
				if(a[i]==p[j]) cnt[j]++;
		}
		if(cnt[11]){
			cout<<"YES"<<endl;
			continue;
		}
		for(i=0;i<11;i++){
			cnt[i+1]+=cnt[i]/2;
			cnt[i]%=2;
		}
		if(!cnt[11]){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
}