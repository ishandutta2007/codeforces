#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,d,e;
	cin>>n>>d>>e;
	int mi=INT_MAX;
	for(int i=0;i<=n/(e*5);i++){
		mi=min(mi,(n-e*5*i)%d);
	}
	printf("%d\n",mi);
    return 0;
}