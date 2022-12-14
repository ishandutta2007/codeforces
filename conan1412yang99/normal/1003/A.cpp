#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	int b[101];
	cin>>a;
	for(int i = 0 ; i < a ; i++) cin >> b[i];
	if(a == 1) cout<<1;
	else{
		int c = 1, m = 0;
		sort(b, b+a);
		for(int i = 0 ; i < a-1 ; i++){
			if(b[i] == b[i+1]) c++;				
			else if(c > m) m = c , c = 1;
			else c = 1;
		}
		if(c > m) m = c , c = 1;
		cout<<m;
	}
	return 0;
}