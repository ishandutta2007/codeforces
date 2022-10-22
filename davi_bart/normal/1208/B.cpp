#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> v;
unordered_map<int,int> p;
set<int> troppi;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			p[a]++;
			v.push_back(a);
			if(p[a]==2)troppi.insert(a);
		}
		if(troppi.size()==0){
      cout<<0;
      return 0;
		}
		int mi=100000;
		int sx=0,dx=0;
		for(int i=0;i<N;i++){
			p[v[i]]--;
			if(p[v[i]]==1)troppi.erase(v[i]);
			if(troppi.size()==0){
				mi=min(mi,dx-sx+1);
				while(sx<dx){
					if(p[v[sx]]==1)break;
					p[v[sx]]++;
					sx++;
				}
				mi=min(mi,dx-sx+1);
			}
			dx++;
		}
		cout<<mi;
		return 0;
}