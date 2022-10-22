#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int inf=0x3f3f3f3f;
int n,m;
int a[N];
int b[N],c[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-i;
			c[i]=a[i]+i;
		}
		bool flag=0;
		int mn=inf,mnp=0;
		for(i=1;i<=n;i++){
			if(b[i]>mn){
				flag=1;
				cout<<"YES"<<endl<<mnp<<" "<<i<<endl;
				break;
			}
			if(b[i]<mn){
				mn=b[i];
				mnp=i;
			}
		}
		if(flag) continue;
		mn=inf;mnp=0;
		for(i=n;i;i--){
			if(c[i]>mn){
				flag=1;
				cout<<"YES"<<endl<<i<<" "<<mnp<<endl;
				break;
			}
			if(c[i]<mn){
				mn=c[i];
				mnp=i;
			}
		}
		if(flag) continue;
		cout<<"NO"<<endl;
	}
	return 0;
}