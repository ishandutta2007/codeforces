#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) for(long long i=0; i<a; i++)
 
using namespace std;

int main(){
	ll n,bad,x;
	string s;
	cin >> n >> s;
	vector<ll> vec;
	bad=0;
	loop(n){
		if(s[i]=='A') vec.push_back(i);
	}
	loop(vec.size()){
		if(i!=vec.size()-1) bad=bad+vec.at(i+1)-vec.at(i)-1;
		else bad=bad+n-1-vec.at(i);
		if(i!=0) bad=bad+vec.at(i)-vec.at(i-1)-1;
		else bad=bad+vec.at(i);
	}
	vec.clear();
	loop(n){
		if(s[i]=='B') vec.push_back(i);
	}
	loop(vec.size()){
		if(i!=vec.size()-1) bad=bad+vec.at(i+1)-vec.at(i)-1;
		else bad=bad+n-1-vec.at(i);
		if(i!=0) bad=bad+vec.at(i)-vec.at(i-1)-1;
		else bad=bad+vec.at(i);
	}
	loop(n-1){
		if(s[i]!=s[i+1]) bad--;
	}
	ll good=n*(n-1)/2-bad;
	cout << good << endl;
	return 0;
}