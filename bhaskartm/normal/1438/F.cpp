#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back

int cnt[(1<<18)];
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mt19937_64 rnd(time(NULL));
	int h;
	cin>>h;
	int n=(1<<h)-1;
	for(int i=0; i<420; i++){
		int x1=(rnd()%n)+1;
		int x2;
		int x3;
		while(1){
			x2=(rnd()%n)+1;
			if(x2==x1){
				continue;
			}
			else{
				break;
			}
		}
		while(1){
			x3=(rnd()%n)+1;
			if(x3==x1 || x3==x2){
				continue;
			}
			else{
				break;
			}
		}
		cout<<"? "<<x1<<" "<<x2<<" "<<x3<<endl;
		int y;
		cin>>y;
		cnt[y]++;
	}
	vector<pair<int, int>>vec;
	for(int i=1; i<=n; i++){
		vec.pb({cnt[i], i});
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	int c1=vec[0].s;
	int c2=vec[1].s;
	for(int i=1; i<=n; i++){
		if(i==c1 || i==c2){
			continue;
		}
		cout<<"? "<<c1<<" "<<c2<<" "<<i<<endl;
		int x;
		cin>>x;
		if(x==i){
			cout<<"! "<<i<<endl;
			return 0;
		}
	}
	
	return 0;
}