#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int c[3];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			c[a%2]++;
		}
		cout<<min(c[0],c[1]);
		return 0;
}