#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		string a;
		cin>>a;
		int aperte=0;
		bool perso=0;
		if(N%2){
			cout<<"No";
			return 0;
		}
		for(int i=0;i<a.size();i++){
			if(a[i]==')')aperte--;
			else aperte++;
			if(aperte==-1){
				if(perso){
					cout<<"No";
					return 0;
				}
				perso=1;
				aperte=0;
				a+=')';
			}
		}
		if(aperte==0)cout<<"Yes";
		else cout<<"No";
		return 0;
}