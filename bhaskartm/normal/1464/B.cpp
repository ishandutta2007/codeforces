#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string st;
	cin>>st;
	int x;
	int y;
	cin>>x>>y;
	string st2;
	int mini=1e18;
	int c0=0;
	int c1=0;
	for(int i=0; i<st.size(); i++){
		if(st[i]=='0' || st[i]=='?'){
			c0++;
		}
		else{
			c1++;
		}
	}
	int ans=0;
	int b0=0;
	int b1=0;
	int ct=c0;
	int bt=b0;
	for(int i=0; i<st.size(); i++){
		if(st[i]!='1'){
			ct--;
			bt++;
		}
		else{
			ans+=(x*bt+y*ct);
		}
	}
	mini=ans;
	int ans2=ans;
	for(int i=0; i<st.size(); i++){
		if(st[i]=='1'){
			b1++;
			c1--;
			continue;
		}
		if(st[i]=='0'){
			b0++;
			c0--;
			continue;
		}
		c0--;
		ans-=x*c1;
		ans-=y*b1;
		ans+=b0*x;
		ans+=c0*y;
		b1++;
		mini=min(mini, ans);
	}
	c0=0;
	c1=0;
	b0=0;
	b1=0;
	for(int i=0; i<st.size(); i++){
		if(st[i]!='1'){
			b0++;
		}
		else{
			b1++;
		}
	}
	for(int i=st.size()-1; i>=0; i--){
		if(st[i]=='0'){
			b0--;
			c0++;
			continue;
		}
		if(st[i]=='1'){
			b1--;
			c1++;
			continue;
		}
		b0--;
		ans2+=c0*y;
		ans2+=b0*x;
		ans2-=b1*y;
		ans2-=c1*x;
		mini=min(ans2, mini);
		c1++;
		
	}
	cout<<mini;
	return 0;
}