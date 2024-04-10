#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N],cnt[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int cnt1=0,mxp=0;
	for(i=1;i<N;i++){
		if(cnt[i]>cnt[mxp]) mxp=i;
		if(cnt[i]==1) cnt1++;
	}
	bool flag=0;
	if(cnt1&1){
		if(cnt[mxp]<=2){
			cout<<"NO";
			return 0;
		}
		cout<<"YES"<<endl;
		bool f2=0;
		for(i=1;i<=n;i++){
			if(cnt[a[i]]==1){
				if(flag) cout<<"A";
				else cout<<"B";
				flag=!flag;
			}
			else if(mxp==a[i]){
				if(!f2) cout<<"A";
				else cout<<"B";
				f2=1;
			}
			else cout<<"A";
		}
	}
	else{
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++){
			if(cnt[a[i]]==1){
				if(flag) cout<<"A";
				else cout<<"B";
				flag=!flag;
			}
			else cout<<"A";
		}
	}
	return 0;
}