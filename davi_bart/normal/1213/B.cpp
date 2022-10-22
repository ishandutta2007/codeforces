#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			int N;
			cin>>N;
			int tot=0;
			int mi=10000000;
			vector<int> v;
			for(int i=0;i<N;i++){
				int a;
				cin>>a;
				v.push_back(a);
			}
			for(int i=N-1;i>=0;i--){
				if(v[i]>mi)tot++;
				mi=min(mi,v[i]);
			}
			cout<<tot<<'\n';
		}
		return 0;
}