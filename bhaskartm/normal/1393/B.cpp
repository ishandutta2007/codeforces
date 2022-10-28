#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'
int cnt[100005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	set<pair<int, int>>se;
	for(int i=1; i<100005; i++){
		se.insert({cnt[i], i});
	}
	int q;
	cin>>q;
	
	while(q--){
		char c;
		int x;
		cin>>c>>x;
		if(c=='+'){
			se.erase({cnt[x], x});
			se.insert({cnt[x]+1, x});
			cnt[x]++;
		}
		else{
			se.erase({cnt[x], x});
			se.insert({cnt[x]-1, x});
			cnt[x]--;
		}
		auto it=se.end();
		bool b=1;
		int sum=0;
		for(int i=0; i<=3; i++){
			it--;
			int num=(*it).f;
			if(i==0 && num<4){
				b=0;
				break;
			}
			sum+=((num/2)*2);
		}
		if(b==0){
			cout<<"NO"<<endl;
			continue;
		}
		if(sum>=8){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}