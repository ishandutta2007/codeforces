#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

ll a[3];

int main(){
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a+3);
	if(2*(a[0] + a[1]) >= a[2]){
		cout<<(a[0]+a[1]+a[2])/3<<'\n';
	}
	else{
		cout<<(a[0]+a[1])<<'\n';
	}
}