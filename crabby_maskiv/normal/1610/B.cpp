#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
int a[N];
int c[N];
vector<int> v[N];
int t[N];
bool check(int x){
	int la=n+1;
	for(int i=1;i<=n;i++){
		if(a[i]==x) continue;
		if(t[i]>la) return 0;
		la=t[i];
	}
	return 1;
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++){
			c[i]=0;
			v[i].clear();
		}
		for(i=n;i;i--) v[a[i]].push_back(i);
		for(i=1;i<=n;i++){
			t[i]=v[a[i]][c[a[i]]];
			c[a[i]]++;
		}
		bool f=0;
		for(i=2;i<=n;i++){
			if(t[i]>t[i-1]){
				if(check(a[i-1])) cout<<"YES"<<endl;
				else if(check(a[i])) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
				f=1;
				break;
			}
		}
		if(!f){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}