#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
int cnt[256];
bool odd[256];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string st;
	cin>>st;
	for(auto ch:st){
		cnt[int(ch)]++;
	}
	int num=0;
	vector<int>v1;//odd
	vector<int>v2;//even
	for(int i=0; i<256; i++){
		if(cnt[i]%2==1){
			odd[i]=1;
			num++;
			v1.pb(i);
			
		}
		else if(cnt[i]>0){
			v2.pb(i);
		}
	}
	vector<char>ve;
	for(auto u:v2){
		for(int i=0; i<cnt[u]; i++){
			ve.pb(char(u));
		}
	}
	for(auto u:v1){
		for(int i=0; i<cnt[u]-1; i++){
			ve.pb(char(u));
		}
	}
	for(auto u:v1){
		ve.pb(char(u));
	}
	for(int i=1; i<=n; i++){
		
		if(n%i!=0){
			continue;
		}
		int sz=n/i;
		if(sz%2==0 && num>0){
			continue;
		}
		if(sz%2==1 && num>i){
			continue;
		}
		if(sz%2==1 && num<=i && (i-num)%2==1){
			continue;
		}
		vector<int>pos;
		vector<char>ans;
		ans.resize(n);
		if(sz%2==0){
			
			for(int j=0; j<i; j++){
				for(int k=0; k<sz/2; k++){
					pos.pb(j*sz+k);
					pos.pb(j*sz+sz-1-k);
				}
			}
			int pt=0;
			for(auto u:pos){
				ans[u]=ve[pt];
				pt++;
			}
			pt=0;
			cout<<i<<endl;
			for(int j=0; j<i; j++){
				for(int k=0; k<sz; k++){
					cout<<ans[pt];
					pt++;
				}
				cout<<" ";
			}	
			return 0;
		}
		
		for(int j=0; j<i; j++){
			for(int k=0; k<(sz/2); k++){
				pos.pb(j*sz+k);
				pos.pb(j*sz+sz-1-k);
			}
		}
		for(int j=0; j<i; j++){
			pos.pb(j*sz+(sz/2));
		}
		int pt=0;
		for(auto u:pos){
			ans[u]=ve[pt];
			pt++;
		}
		pt=0;
		cout<<i<<endl;
		for(int j=0; j<i; j++){
			for(int k=0; k<sz; k++){
				cout<<ans[pt];
				pt++;
			}
			cout<<" ";
		}
		return 0;
		
		
		
		
	}
	
	return 0;
}