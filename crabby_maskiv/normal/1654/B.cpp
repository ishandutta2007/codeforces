#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
map<char,int> mp;
char a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>(a+1);
		n=strlen(a+1);
		for(i=1;i<=n;i++) mp[a[i]]++;
		for(i=1;i<=n;i++){
			if(mp[a[i]]==1) break;
			mp[a[i]]--;
		}
		for(;i<=n;i++) cout<<a[i];
		cout<<endl;
		mp.clear();
	}
	return 0;
}