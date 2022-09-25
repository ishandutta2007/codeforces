#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int n,g,s,b;
		cin >> n;
		int a[n];
		loop(n)	cin >> a[i];
		if(n==1){
			cout << "0 0 0\n";
			continue;
		}
		vector<int> vec;
		vec.clear();
		loop(n-1) if(a[i]!=a[i+1]) vec.push_back(i+1);
		vec.push_back(n);
		g=vec[0];
		s=b=0;
		loop(vec.size()){
			if(i==0) continue;
			if(vec[i]*2>n) break;
			if(s==0) if(vec[i]>2*g) s=vec[i]-g;
			if(s>0) if(vec[i]>2*g+s) b=vec[i]-g-s;
		}
		if(b==0){
			cout << "0 0 0\n";
			continue;
		}
		cout << g << " " << s << " " << b << "\n";
	}
	return 0;
}