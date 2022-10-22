#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
char a[N];
int pre[N],suf[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		pre[0]=0;suf[n+1]=0;
		cin>>(a+1);
		for(i=1;i<=n;i++){
			if(a[i]=='1') pre[i]=i;
			else pre[i]=pre[i-1];
		}
		for(i=n;i;i--){
			if(a[i]=='1') suf[i]=i;
			else suf[i]=suf[i+1];
		}
		for(i=1;i<=n;i++){
			if(a[i]=='1') cout<<1;
			else{
				if(!pre[i]&&!suf[i]) cout<<0;
				else if(!pre[i]&&suf[i]) cout<<(suf[i]-i<=m);
				else if(pre[i]&&!suf[i]) cout<<(i-pre[i]<=m);
				else{
					if(i-pre[i]==suf[i]-i) cout<<0;
					else if(i-pre[i]>m&&suf[i]-i>m) cout<<0;
					else cout<<1;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}