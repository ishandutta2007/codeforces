#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int r1, s1, p1;
	int r2, s2, p2;
	cin>>r1>>s1>>p1>>r2>>s2>>p2;
	cout<<max(0LL, r1-r2-p2)+max(0LL, s1-r2-s2)+max(0LL, p1-s2-p2)<<" ";
	cout<<min(r1, s2)+min(s1, p2)+min(p1, r2)<<endl;
	return 0;
}