#include<bits/stdc++.h>
const int N=200500,P=21;
using namespace std;

int s[P][N];

void init(){
	for(int i=1;i<N;i++)
		for(int j=0;j<P;j++){
			s[j][i]=s[j][i-1];
			if(i>>j&1)
				s[j][i]++;
		}
}

void solve(){
	int l,r,ans=0;cin>>l>>r;l--;
	for(int i=0;i<P;i++)
		ans=max(s[i][r]-s[i][l],ans);
	cout<<r-l-ans<<'\n';
}

int main(){
	init();
	int _T=1;cin>>_T;
	while(_T--)solve();
}