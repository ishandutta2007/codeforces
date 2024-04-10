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
const int X=128;
int n, x;
double p[X];
struct mat {
	double a[X][X];
	mat() {}
	mat operator*(const mat &t) {
		mat ans;
		for (int i=0; i<X; i++) {
			for (int j=0; j<X; j++) {
				ans.a[i][j]=(double)0;
				for (int k=0; k<X; k++) {
					ans.a[i][j]+=a[i][k]*t.a[k][j];
				}
			}
		}
		return ans;
	}
};
mat m, res;
mat matpow(int sb) {
	if (sb==1) {
		return m;
	}
	if (sb&1) {
		return m*matpow(sb-1);
	}
	mat oh=matpow(sb>>1);
	return oh*oh;
}
int main() {
	scanf("%d%d", &n, &x);
	for (int i=0; i<=x; i++) {
		scanf("%lf", &p[i]);
	}
	for (int i=0; i<X; i++) {
		for (int j=0; j<X; j++) {
			m.a[i][j]=p[i^j];
		}
	}
	res=matpow(n);
	printf("%.8lf\n", (double)1-res.a[0][0]);
	return 0;
}