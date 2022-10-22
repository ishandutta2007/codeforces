#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
char a[N],b[N];
int to[N];
int d[N];
int main(){
	int i,j;
	cin>>n;
	cin>>(a+1);
	for(i=n;i;i--) b[i]=a[n-i+1];
	for(i='a';i<='z';i++){
		int pos=1;
		for(j=1;j<=n;j++){
			if(a[j]==i){
				while(b[pos]!=a[j]) pos++;
				to[j]=pos;
				pos++;
			}
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		for(j=to[i];j<=n;j+=lbt(j)) ans+=d[j];
		for(j=to[i];j;j-=lbt(j)) d[j]++;
	}
	cout<<ans;
	return 0;
}