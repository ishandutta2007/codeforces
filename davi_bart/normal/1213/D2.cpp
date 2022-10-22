#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> p[200010];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,K;
		cin>>N>>K;
		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			int h=0;
			while(1){
				p[a].push_back(h);
				h++;
				if(a==0)break;
				a/=2;
			}
		}
		for(int i=0;i<200010;i++)sort(p[i].begin(),p[i].end());
		int mi=100000000;
		for(int i=0;i<200001;i++){
			if(p[i].size()<K)continue;
			int tot=0;
			for(int j=0;j<K;j++){
				tot+=p[i][j];
			}
			mi=min(mi,tot);
		}
		cout<<mi;
		return 0;
}