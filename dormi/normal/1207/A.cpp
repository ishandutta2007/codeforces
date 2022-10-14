#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int b,p,f;
		int h,c;
		cin>>b>>p>>f>>h>>c;
		int ans=0;
		if(h>=c){
			int am=min(b/2,p);
			b-=2*am;
			ans+=h*am;
			am=min(b/2,f);
			ans+=c*am;
		}
		else{
			int am=min(b/2,f);
			b-=2*am;
			ans+=c*am;
			am=min(b/2,p);
			ans+=h*am;
		}
		printf("%d\n",ans);
	}
    return 0;
}