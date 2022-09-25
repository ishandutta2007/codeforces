#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,day,x;
	cin >> n;
	int a[n];
	loop(n) cin >> a[i];
	set<int> s,s1;
	vector<int> vec;
	day=0;
	x=0;
	loop(n){
		if(a[i]>0){
			if(s.find(a[i])!=s.end()||s1.find(a[i])!=s1.end()){
				cout << -1 << "\n";
				return 0;
			}
			s.insert(a[i]);
			s1.insert(a[i]);
		}
		else if(a[i]<0){
			if(s.find(-a[i])==s.end()){
				cout << -1 << "\n";
				return 0;
			}
			s.erase(-a[i]);
		}
		x++;
		if(s.empty()){
			vec.push_back(x);
			x=0;
			day++;
			s1.clear();
		}
	}
	if(!s.empty()){
		cout << -1 << "\n";
		return 0;
	}
	cout << day << "\n";
	loop(vec.size()){
		cout << vec[i] << " ";
	}
	cout << "\n";
	return 0;
}