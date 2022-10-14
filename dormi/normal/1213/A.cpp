#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int par[2]={};
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		par[in%2]+=1;
	}
	printf("%d\n",min(par[0],par[1]));
    return 0;
}