#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef long long ll;

bool xec(int x, int y){
	if(x > y) return true;
	return false;
}

int main(){
	int n;
	cin>>n;
	VI V(n);
	for(int i = 0;i < n;++i) cin>>V[i];
	sort(V.begin(),V.end(),xec);
	for(int i = 1;i < n;++i) V[i]+=V[i-1];
	ll k = V[n-1];
	for(int i = n-1;i > 0;--i) k += V[i];
	cout<<k<<endl;
}