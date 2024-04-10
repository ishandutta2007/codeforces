#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			int N;
			bool j=0;
			cin>>N;
			vector<int> p;
			for(int i=0;i<N;i++){
				int a;
				cin>>a;
				p.push_back(a-1);
			}
			if(N==1){
        cout<<"YES"<<'\n';
        continue;
			}
			for(int i=1;i<N;i++){
				if(p[i]!=(p[i-1]+1)%N)break;
				if(i==N-1){
					cout<<"YES"<<'\n';
					j=1;
					break;
				}
			}
			if(j)continue;
			for(int i=1;i<N;i++){
				if(p[i]!=(p[i-1]-1+N)%N)break;
				if(i==N-1){
					cout<<"YES"<<'\n';
					j=1;
					break;
				}
			}
			if(!j)cout<<"NO"<<'\n';
		}
		return 0;
}