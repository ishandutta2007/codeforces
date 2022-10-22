#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3f;
const ll mod=19260817;
int n,m;
int cnt[200];
string s[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s[i];
		cnt[s[i][0]]++;
	}
	int ans=0;
	for(i='a';i<='z';i++){
		int k1=(cnt[i]+1)/2,k2=cnt[i]/2;
		ans+=(k1*(k1-1)/2);
		ans+=(k2*(k2-1)/2);
	}
	cout<<ans;
	return 0;
}