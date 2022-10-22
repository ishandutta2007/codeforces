#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		int mn=1,mx=1;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=2;i<=n;i++){
			if(a[i]<a[mn]) mn=i;
			if(a[i]>a[mx]) mx=i;
		}
		cout<<mx<<" "<<mn<<endl;
	}
	return 0;
}