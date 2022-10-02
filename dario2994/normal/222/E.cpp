#include <iostream>
#include <fstream>
#define MAXD 55
#define mod ULL(1000000007)
#define rep(i) for(int i=1;i<=m;i++)
typedef unsigned long long ULL;
using namespace std;
ULL n;
int m;

short int T(char u){
	if('a'<= u and u<= 'z')return 1+u-'a';
	else return 27+u-'A';
}

class matrix{
	public:
		int d;
		ULL a[MAXD][MAXD];
		matrix(int u){
			d=u;
		}
		matrix operator * (matrix R){
			matrix res=matrix(m);
			rep(i)rep(j){
				res.a[i][j]=0;
				rep(l)res.a[i][j]=(res.a[i][j]+a[i][l]*R.a[l][j])%mod;
			}
			return res;
		}
		
};

matrix id(){
	matrix res=matrix(m);
	rep(i)rep(j)res.a[i][j]=0;
	rep(i)res.a[i][i]=1;
	return res;
}

matrix pot(matrix A, ULL e){
	if(e==0)return id();
	if(e%2==1)return A*pot(A*A,e/2);
	else return pot(A*A,e/2);
}

int main(){
	int k;
	cin >> n >> m >> k;
	matrix M=matrix(m);
	rep(i)rep(j)M.a[i][j]=1;
	for(int i=0;i<k;i++){
		char x,y;
		cin >> x >> y;
		M.a[T(x)][T(y)]=0;
	}
	matrix S=id();
	matrix res=S*pot(M,n-1);
	ULL ris=0;
	rep(i)rep(j)ris=(ris+res.a[i][j])%mod;
	cout << ris;
}