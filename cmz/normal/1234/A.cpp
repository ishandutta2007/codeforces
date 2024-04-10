#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;
void up() {
	int n;
	cin>>n;
	int ss=0;
	for (int i=1; i<=n; i++) {
		int l;
		cin>>l;
		ss+=l;
	}
	cout<<(ss+n-1)/n<<"\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin>>q;
	while (q--) up();
}