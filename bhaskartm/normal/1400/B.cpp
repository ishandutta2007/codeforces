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
	int t;
	cin>>t;
	while(t--){
		int p, f;
		cin>>p>>f;
		int cs, cw;
		cin>>cs>>cw;
		int s, w;
		cin>>s>>w;
		if(s>w){
			swap(s, w);
			swap(cs, cw);
		}
		int maxi=(p/s)+(f/s);
		if(maxi<cs){
			cout<<maxi<<endl;
			continue;
		}
		int maxi2=cs;
		for(int i=0; i<=cs; i++){
			if(i*s>p || (cs-i)*s>f){
				continue;
			}
			int val1=((p-(i*s)))/w;
			int val2=((f-((cs-i)*s)))/w;
			if(val1+val2>cw){
				maxi2=max(maxi2, cw+cs);
			}
			else{
				maxi2=max(maxi2, val1+val2+cs);
			}
		}
		cout<<maxi2<<endl;
	}
	return 0;
}