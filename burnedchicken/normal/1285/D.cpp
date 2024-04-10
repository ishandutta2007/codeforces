#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;

int dgts(int n){
	int n1=n;
	int x=0;
	while(n1>0){
		n1=n1/2;
		x++;
	}
	return x;
}

int solve(vector<int> a){
	if(a.size()==1) return 0;
	int Maxnum=-1;
	loop(a.size()) Maxnum=max(Maxnum,a[i]);
	if(Maxnum==0) return 0;
	int Max=dgts(Maxnum)-1;
	int x,y;
	int z=pow2(Max);
	x=y=0;
	loop(a.size()){
		if(a[i]>=z) x++;
		else y++;
	}
	vector<int> a1,a2;
	if(y==0){
		loop(a.size()) a1.push_back(a[i]-z);
		return solve(a1);
	}
	loop(a.size()){
		if(a[i]>=z) a1.push_back(a[i]-z);
		else a2.push_back(a[i]);
	}
	return pow2(Max)+min(solve(a1),solve(a2));
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	loop(n) cin >> a[i];
	cout << solve(a) << "\n";
	return 0;
}