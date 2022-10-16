#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int ask(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}

int main(){
	int n;
	cin>>n;
	int l = 1, m, r = n-1;
	while(l <= r){
		m = l+r>>1;
		if(ask(m) < ask(m+1))
			r = m-1;
		else
			l = m+1;
	}
	cout<<"! "<<l<<endl;
}