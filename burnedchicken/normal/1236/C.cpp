#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	ll n;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=0; j<n; j++){
			if(j%2==0) cout << j*n+i << " ";
			else cout << j*n+n+1-i << " ";
		}
		cout << endl;
	}
	return 0;
}