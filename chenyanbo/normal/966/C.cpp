#include<bits/stdc++.h>
using namespace std;

int fl,n;
multiset<long long>g[65];
long long x,h[100005],cc;

int main()
{
	cin>>n;//()
	for(int i=1; i<=n; ++i){
		cin>>x;
		for(int j=59; j>=0; --j)if(x>=1ll<<j){
			g[j].insert(x);
			break;
		}
	} 
	for(int i=0; i<=59; ++i)if(g[i].size()){
		h[1]=cc=*g[i].begin();
		g[i].erase(g[i].begin());
		break;
	}
	for(int i=2; i<=n; ++i){
		fl=0;
		for(int j=0; j<=59; ++j)if(g[j].size()){
			if(!(cc&(1ll<<j))){
				fl=1;
				h[i]=*g[j].begin();
				g[j].erase(g[j].begin());
				cc^=h[i];
				break;
			}
		}
		if(!fl){
			puts("No");
			return 0;	
		}
	}
	puts("Yes");
	for(int i=1; i<=n; ++i)printf("%lld ",h[i]);
}