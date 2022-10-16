#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 3e5+5;

int n;
ll a[MM], va, vb;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		va += a[i]/2;
		vb += a[i]/2;
		if(a[i]%2){
			if(i%2)
				va++;
			else
				vb++;
		}
	}
	cout<<min(va, vb)<<'\n';
}