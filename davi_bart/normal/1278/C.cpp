#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int> k;
unordered_map<int,bool> vis;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			k.clear();
			vis.clear();
			int N;
			cin>>N;
			vector<int> v;
			vector<int> v1;
			for(int i=0;i<N;i++){
				int a;
				cin>>a;
        if(a==1)v.push_back(a);
        else v.push_back(-1);
			}
			k[0]=N;
			vis[0]=1;
			k[v[0]]=N-1;
      vis[v[0]]=1;
			for(int i=1;i<N;i++){
				v[i]+=v[i-1];
				k[v[i]]=N-i-1;
				vis[v[i]]=1;
			}

			for(int i=0;i<N;i++){
				int a;
				cin>>a;
				if(a==1)v1.push_back(a);
				else v1.push_back(-1);
			}
			reverse(v1.begin(),v1.end());
			int mi=2*N;
			if(vis[-v1[0]])mi=min(mi,N-1+k[-v1[0]]);
			if(vis[0])mi=min(mi,N+k[0]);
			for(int i=1;i<N;i++){
				v1[i]+=v1[i-1];
				if(vis[-v1[i]])mi=min(mi,N-i-1+k[-v1[i]]);
			}
			cout<<mi<<'\n';

		}
    return 0;
}