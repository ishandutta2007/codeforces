#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int b,g,n;
	cin>>b>>g>>n;
	printf("%d\n",min(b-max(0,n-g),min(g-max(0,n-b),n))+1);
	return 0;
}