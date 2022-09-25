#include <iostream>

using namespace std;
int main(){
	int q,n,x,sum;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		sum=0;
		for(int i=0; i<n; i++){
			cin >> x;
			if(x<=2048) sum=sum+x;
		}
		if(sum>=2048) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}