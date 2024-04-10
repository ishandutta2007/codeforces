#include<bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		ll x;
		cin >> x;
		if(x<=14){
			cout << "NO\n";
			continue;
		}
		if(x%14==0||x%14>=7){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}