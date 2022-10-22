#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=30;i>=0;i--){
			int cnt=0;
			for(j=1;j<=n;j++) cnt+=bool(a[j]&(1<<i));
			if(cnt&1){
				if((cnt>>1)%2==0) cout<<"WIN"<<endl;
				else if((n-cnt)%2==1) cout<<"WIN"<<endl;
				else cout<<"LOSE"<<endl;
				break;
			}
		}
		if(i<0) cout<<"DRAW"<<endl;
	}
	return 0;
}