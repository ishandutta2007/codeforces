#include <bits/stdc++.h>

#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	int t,n;
	cin >> t;
	string str;
	int l,r;
	loop(t){
		cin >> n >> str;
		l=0;
		r=0;
		for(int j=0; j<n; j++){
			if(str[j]=='1') break;
			l++;
		}
		for(int j=n-1; j>=0; j--){
			if(str[j]=='1') break;
			r++;
		}
		cout << max(n,2*n-2*min(l,r)) << endl;
	}
	return 0;
}