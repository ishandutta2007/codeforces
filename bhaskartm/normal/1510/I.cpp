#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
 
#define f first
#define s second
#define pb push_back
#define T long double
T po[105];
int cnt[1005];
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mt19937 rnd(time(NULL));

	int n, m;
	cin>>n>>m;
	po[0]=1;
	for(int i=1; i<105; i++){
		po[i]=po[i-1]/1.5;
	}
	
	while(m--){
		string st;
		cin>>st;
		T w0=0;
		T w1=0;
		int mini=1e9;
		for(int i=0; i<n; i++){
			mini=min(mini, cnt[i]);
		}
		for(int i=0; i<n; i++){
			cnt[i]-=mini;
		}
		for(int i=0; i<st.size(); i++){
			if(cnt[i]>=105){
				continue;
			}
			if(st[i]=='0'){
				w0+=po[cnt[i]];
			}
			else{
				w1+=po[cnt[i]];
			}
		}
		int val=floor(100*(w0/(w0+w1)));
		int x=rnd();
		x=abs(x);
		x=x%100;
		if(x<=val){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
		int y;
		cin>>y;
		for(int i=0; i<n; i++){
			if(int(st[i]-'0')!=y){
				cnt[i]++;
			}
		}
		
		
 
	}
	
	
	return 0;
}