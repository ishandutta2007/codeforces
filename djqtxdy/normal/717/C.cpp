#include<iostream>
#include<sstream>
#include<fstream>
#include<set>
#include<iomanip>
#include<map>
#include<queue>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdio>
#include<ctime>
#include<ios>
#include<utility>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define rep(i,j,k) for(int (i)=(j);(i)<=k;(i)++)
using namespace std;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef long long ll;
typedef vector<ll>vll;
typedef pair<int,int>pii;
typedef vector<pii>vpii;
typedef map<int,int>mii;
typedef double db;
typedef float fo;
int n,a[100005],b[100005];
int mod=10007;
ll ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		ans+=(a[i]%mod)*(b[i]%mod);
	}
	cout<<ans%mod;
	return 0;
}