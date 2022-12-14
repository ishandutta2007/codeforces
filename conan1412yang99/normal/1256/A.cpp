#include <bits/stdc++.h>

using namespace std;

int main(){
	int l;
	cin>>l;
	while(l--){
		int a,b,n,s,p;
		cin>>a>>b>>n>>s;
		if (n == 1){
			if(a+b >= s) cout<<"yeS";
			else cout<<"nO";
			cout << endl;	
	    }
		else{
			p = s/n;
			if(p <= a) s = s%n;
			else s -= a*n; 
			if(s > 0){
				if(b >= s) cout<<"yeS";
				else cout<<"nO";
			}
			else cout<<"yEs";
			cout << endl;	
		}
	}
	return 0;
}