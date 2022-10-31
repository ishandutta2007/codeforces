#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	string s1,s2;
	int n,m,k;cin>>n>>m>>k;
	cin>>s1>>s2;
	sort(s1.begin(),s1.end());	
	sort(s2.begin(),s2.end());	
	string res;
	int pr=-1,cnt=0;
	int a=0,b=0;
	for(int i=0;i<n+m;i++){
		int fl;
		if(a==n||(b!=m&&s2[b]<s1[a]))
			fl=1;
		else fl=0;
		if(fl==pr&&cnt==k)fl=1-fl;
		if(fl)res+=s2[b++];
		else res+=s1[a++];
		if(a==n||b==m)break;
		if(fl==pr)cnt++;
		else pr=fl,cnt=1;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}