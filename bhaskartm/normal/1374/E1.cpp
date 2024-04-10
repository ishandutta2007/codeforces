#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define endl '\n'
#define pb push_back


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	vector<int>a;
	vector<int>b;
	vector<int>both;
	for(int i=0; i<n; i++){
		int t, a1, b1;
		cin>>t>>a1>>b1;
		if(a1==1 && b1==1){
			both.pb(t);
			continue;
		}
		if(a1==1 && b1==0){
			a.pb(t);
			continue;
		}
		if(a1==0 && b1==1){
			b.pb(t);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(both.begin(), both.end());
	int v1=a.size();
	int v2=b.size();
	int v3=both.size();
	int v12=min(v1, v2);
	if(v12+v3<k){
		cout<<-1<<endl;
		return 0;
	}
	int prea[a.size()+1];
	int preb[b.size()+1];
	int preboth[both.size()+1];
	prea[0]=0;
	preb[0]=0;
	preboth[0]=0;
	for(int i=1; i<=a.size(); i++){
		prea[i]=prea[i-1]+a[i-1];
	}
	for(int i=1; i<=b.size(); i++){
		preb[i]=preb[i-1]+b[i-1];
	}
	for(int i=1; i<=both.size(); i++){
		preboth[i]=preboth[i-1]+both[i-1];
	}
	int mini=2e9;
	
	for(int i=0; i<=both.size(); i++){
		if(i>k){
			continue;
		}
		int val=preboth[i];
		
		if(i+v12<k){
			continue;
		}
		val+=prea[k-i];
		val+=preb[k-i];

		mini=min(val, mini);
		
	}
	cout<<mini<<endl;
	return 0;
}