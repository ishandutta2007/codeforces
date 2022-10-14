#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	lli arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)sc(arr[i][j]);
	}
	lli gc=0;
	for(int i=1;i<n;i++){
		gc=__gcd(gc,arr[0][i]);
	}
	for(lli i=1;i<=sqrt(gc);i++){
		if(gc%i==0){
			lli te[n];
			te[0]=i;
			for(int j=1;j<n;j++)te[j]=arr[0][j]/i;
			bool work=true;
			for(int j=1;work&&j<n;j++)for(int k=0;work&&k<n;k++)if(k!=j&&te[k]*te[j]!=arr[j][k])work=false;
			if(work){
				for(int j=0;j<n;j++)pr(te[j],"");
				return 0;
			}
			te[0]=gc/i;
			for(int j=1;j<n;j++)te[j]=arr[0][j]/(gc/i);
			work=true;
			for(int j=1;work&&j<n;j++)for(int k=0;work&&k<n;k++)if(k!=j&&te[k]*te[j]!=arr[j][k])work=false;
			if(work){
				for(int j=0;j<n;j++)pr(te[j],"");
				return 0;
			}
		}
	}
    return 0;
}