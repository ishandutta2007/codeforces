#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif


const int INF=(int)1e9+7;

void minup(int &a,int b){
	a=min(a,b);
}

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		string s;
		cin>>n>>s;
		assert((int)s.size()==n);
		vector<int>digits(n);
		for (int i=0;i<n;i++){
			char ch=s[i];
			assert(ch=='0'||ch=='1');
			digits[i]=ch-'0';	
		}
		vector<int> dp01(n+1,INF),dp10(n+1,INF),dp00(n+1,INF),dp11(n+1,INF);
		dp01[n]=dp10[n]=dp00[n]=dp11[n]=0;
		for (int i=n-1;i>=0;i--){
			int xval=digits[i];
			assert(xval==0||xval==1);	
			if(xval==0){
				// no op
				minup(dp01[i],min({dp01[i+1],dp11[i+1]}));
				minup(dp00[i],dp00[i+1]);
				// op
				minup(dp11[i],dp00[i+1]+1);
				minup(dp10[i],min({dp01[i+1],dp11[i+1]})+1);
			}else{
				assert(xval==1);
				// no op
				minup(dp10[i],min({dp10[i+1],dp00[i+1]}));
				minup(dp11[i],dp11[i+1]);
				// op
				minup(dp00[i],dp11[i+1]+1);
				minup(dp01[i],min({dp10[i+1],dp00[i+1]})+1);
			}
		}
		cout<<min({dp00[0],dp01[0],dp11[0]})<<"\n";
	}
	
	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */