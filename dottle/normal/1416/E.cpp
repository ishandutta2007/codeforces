#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n,a[N];
set<int> s;
int l,r,A,B;
int res=0,fl;

void update(int x){
	fl=1;
	if(l<=r){
		if(l>=x)l=1,r=0;
		else{
			r=min(r,x-1),swap(l,r);
			l=x-l,r=x-r;
			fl=0;
		}
	}
	A=x-A,B=-B;
	while(s.size()){
		int nw=A+B**s.rbegin();
		if(nw>=x||nw<1)s.erase(*s.rbegin());
		else break;
	}
	while(s.size()){
		int nw=A+B**s.begin();
		if(nw>=x||nw<1)s.erase(*s.begin());
		else break;
	}
}

void solve(){
	cin>>n;
	res=0,B=1,A=0,fl=0;
	s.clear();
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]&1)l=1,r=a[1]-1,res=1;
	else l=r=1[a]>>1;
	for(int i=2;i<=n;i++){
		if(a[i]&1){
			update(a[i]),++res;
			if(s.empty()&&fl)++res,l=1,r=a[i]-1;
		} else {
			if((s.find((a[i]/2-A)*B)!=s.end())||(l<=a[i]/2&&a[i]/2<=r))
				s.clear(),l=r=a[i]/2;
			else update(a[i]),res++,s.insert((a[i]/2-A)*B);
		}
	}
	cout<<res+1<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}