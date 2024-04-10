#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N];
int t[N],l[N],r[N];
int b[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++) cin>>t[i]>>l[i]>>r[i];
	for(i=1;i<=m;i++){
		if(t[i]==1){
			for(j=l[i]+1;j<=r[i];j++)
				b[j]=1;
		}
	}
	for(i=1;i<=m;i++){
		if(t[i]==0){
			for(j=l[i]+1;j<=r[i];j++)
				if(!b[j]) break;
			if(j>r[i]){
				cout<<"NO";
				return 0;
			}
		}
	}
	int pos=0;
	for(i=n;i;){
		int p=i;
		while(b[p]) p--;
		for(j=p;j<=i;j++) a[j]=++pos;
		i=p-1;
	}
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}