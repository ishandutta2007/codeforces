#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
lli conver(char a){
	lli ca=(int)a;
	if(ca<=57)ca-=48;
	else if(ca<=90)ca-=55;
	else ca-=61;
	return ca+1;
}
lli mut=71;
lli mod=1e9+9;
lli precalc[(int)1e6+3];
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string a;
	cin>>a;
	string b;
	vector<lli> hs;
	hs.push_back(conver(a[0]));
	lli te=1e6+2;
	precalc[0]=1;
	for(lli i=1;i<=te;i++){
		precalc[i]=precalc[i-1]*mut%mod;
	}
	for(int i=1;i<a.size();i++){
		hs.push_back((hs.back()+(conver(a[i])*precalc[i]%mod)%mod)%mod);
	}
	for(int i=1;i<n;i++){
		cin>>b;
		lli hs2=0;
		int loc=0;
		int workloc=0;
		while(loc<min(a.size(),b.size())){
			hs2=(hs2+((conver(b[loc])*precalc[loc])%mod)%mod)%mod;
			if((hs2*precalc[(int)a.size()-loc-1]%mod)==make(hs.back()-(((int) hs.size()-loc-2<0)?0:(hs[(int)hs.size()-loc-2])))){
				workloc=loc+1;
			}
			loc++;
		}
		if((int)a.size()-workloc==0){
			a="";
			hs.clear();
		}
		else {
			a.resize((int) a.size() - workloc);
			hs.resize((int) hs.size() - workloc);
		}
		loc=a.size();
		a+=b;
		for(;loc<a.size();loc++){
			hs.push_back(((hs.size()?hs.back():0)+(conver(a[loc])*precalc[loc]%mod)%mod)%mod);
		}
	}
	cout<<a;
	return 0;
}