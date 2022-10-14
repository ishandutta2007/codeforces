#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int cnd,fiam;
	pa(int a=0, int b=0):cnd(a),fiam(b){}
	bool operator<(const pa& rhs) const{
		if(rhs.cnd==cnd){
			return fiam<rhs.fiam;
		}
		return cnd<rhs.cnd;
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		pa am[n];
		int in,in2;
		for(int i=0;i<n;i++){
			cin>>in>>in2;
			am[(in-1)].cnd+=1;
			am[(in-1)].fiam+=in2;
		}
		sort(am,am+n);
		int cnd=0;
		int lastput=INT_MAX;
		int plam[n];
		for(int i=n-1;i>=0;i--){
			int te=max(0,min(am[i].cnd,lastput-1));
			lastput=te;
			cnd+=te;
			plam[i]=te;
		}
		int st=n-1;
		int ficnt=0;
		priority_queue<int> fiam;
		for(int i=n-1;i>=0;i--){
			while(am[i].cnd<plam[st]){
				ficnt+=min(plam[st--],fiam.top());
				fiam.pop();
			}
			fiam.push(am[i].fiam);
		}
		while(!fiam.empty()){
			ficnt+=min(fiam.top(),plam[st--]);
			fiam.pop();
		}
		printf("%d %d\n",cnd,ficnt);
	}
	return 0;
}