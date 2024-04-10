#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
struct pa{
	lli a,b;
	pa(lli x=0, lli y=0):a(x),b(y){}
};
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,q;
	cin>>n>>q;
	lli arr[n];
	lli ma=0;
	lli ind=0;
	for(lli i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>ma){
			ma=arr[i];
			ind=i;
		}
	}
	pa og[ind];
	lli manum=arr[0];
	vector<lli> sor;
	for(lli i=0;i<ind;i++){
		og[i]=pa(manum,arr[i+1]);
		sor.push_back(min(manum,arr[i+1]));
		manum=max(manum,arr[i+1]);
	}
	lli a;
	for(lli i=0;i<q;i++){
		cin>>a;
		a-=1;
		if(a<ind){
			printf("%lli %lli\n",og[a].a,og[a].b);
		}
		else{
			lli act=(a-ind)%(n-1);
			if(act<(n-1)-(lli)sor.size()){
				printf("%lli %lli\n",ma,arr[ind+act+1]);
			}
			else{
				printf("%lli %lli\n",ma,sor[act-((n-1)-(lli)sor.size())]);
			}
		}
	}
	return 0;
}