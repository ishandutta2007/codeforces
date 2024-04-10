#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set<int> p,t;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,M;
		cin>>N;
		for(int i=0;i<N;i++){
        int a;
			cin>>a;
			p.insert(a);
		}
		cin>>M;
		for(int i=0;i<M;i++){
		  int a;
			cin>>a;
			t.insert(a);
		}
		for(int o:p){
			for(int y:t){
				if(p.find(o+y)==p.end() && t.find(o+y)==t.end()){
					cout<<o<<" "<<y;
					return 0;
				}
			}
		}
		return 0;
}