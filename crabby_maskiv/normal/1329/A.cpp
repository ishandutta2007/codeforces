#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int a[N];
int p[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	ll sum=0;
	for(i=1;i<=m;i++){
		cin>>a[i];sum+=a[i];
	}
	if(n<m||n>sum){
		cout<<-1;
		return 0;
	}
	for(i=1;i<=m;i++){
		if(i-1+a[i]>n){
			cout<<-1;
			return 0;
		}
	}
	int pos=n;
	for(i=m;i;i--){
		if(pos==i)
			p[i]=pos--;
		else if(pos-a[i]<i-1){
			p[i]=i;
			pos=i-1;
		}
		else{
			p[i]=pos-a[i]+1;
			pos-=a[i];
		}
	}
	for(i=1;i<=m;i++) cout<<p[i]<<" ";
	return 0;
}