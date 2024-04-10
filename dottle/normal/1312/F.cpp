#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

int x[3]; 
map<pair<int,int>,int>s;

int SG(int a,int b){
	if(b<=0)return 0;
	if(s[{a,b}])return s[{a,b}]-1;
	vector<int> cnt(4);
	for(int i=0;i<3;i++)
		if(i==0||i!=a)
			cnt[SG(i,b-x[i])]++;
	for(int i=0;i<4;i++)
		if(!cnt[i])
			return (s[{a,b}]=i+1)-1;
}

int sg(int k,int X,int l){
	if(X<=100)return SG(k,X);
	else return SG(k,X-(X-200)/l*l);
}

void solve(){
	int n;cin>>n>>x[0]>>x[1]>>x[2];
	vector<int> a(n),cnt(4);
	s.clear();
	int k;
	for(k=1;k<=100;k++){
		int fl=1;
		for(int i=100;i<100+100;i++)
			if((vector<int>){SG(0,i),SG(1,i),SG(2,i)}!=(vector<int>){SG(0,i+k),SG(1,i+k),SG(2,i+k)}){
				fl=0;break;
			}
		if(fl)break;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int X,y;cin>>X;
		y=sg(0,X,k);
		ans^=y;
		for(int i=0;i<3;i++)
			cnt[y^sg(i,X-x[i],k)]++;
	}
	if(ans==0)cout<<0<<endl;
	else cout<<cnt[ans]<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}