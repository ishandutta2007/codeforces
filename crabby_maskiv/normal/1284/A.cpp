#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int n,m;
string s[N],t[N];
int main(){
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>s[i];
	for(i=0;i<m;i++) cin>>t[i];
	int T;cin>>T;
	while(T--){
		int x;cin>>x;
		cout<<s[(x-1)%n]+t[(x-1)%m]<<endl;
	}
	return 0;
}