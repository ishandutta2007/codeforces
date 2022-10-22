#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m; 
int a[N],b[N];
int pos[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(i=1;i<=n;i++) cin>>b[i];
	j=0;
	for(i=1;i<=n;i++){
		if(pos[b[i]]>j){
			cout<<pos[b[i]]-j<<" ";
			j=pos[b[i]];
		}
		else cout<<"0 ";
	}
	return 0;
}