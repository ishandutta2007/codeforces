#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
int T,n,m,l[200004],r[200004];
piii x[200004];
void MAIN(){
	cin>>n>>m;
	l[0]=m,r[0]=m;
	for (int i=1;i<=n;i++) cin>>x[i].first>>x[i].second.first>>x[i].second.second;
	sort (x+1,x+1+n);
	for (int i=1;i<=n;i++){
		l[i]=x[i].second.first,r[i]=x[i].second.second;
		if (r[i-1]+(x[i].first-x[i-1].first)<l[i] || l[i-1]-(x[i].first-x[i-1].first)>r[i]){
			puts("NO");return;
		}
		l[i]=max(l[i],l[i-1]-(x[i].first-x[i-1].first)),r[i]=min(r[i],r[i-1]+(x[i].first-x[i-1].first));
	}
	puts("YES");
}
int main(){
	x[0].first=0;
	cin>>T;
	while (T--) MAIN();
}