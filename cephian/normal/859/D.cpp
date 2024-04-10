#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double a[64][7][7];
	double p[64][64];
	double w[64][7];
	cin >> n;
	int t = (1<<n);
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			double x;
			cin >> x;
			p[i][j] = x/100.0;
		}
		a[i][0][0] = 0;
		w[i][0] = 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<t; j++){
			double totprob = 0;
			for(int k=0; k<t; k++){
				if(((k&(1<<(i-1))) ^ (j&(1<<(i-1)))) && (k>>i) == (j>>i)){
					totprob += w[k][i-1] * p[j][k];
				}
			}
			
			w[j][i] = totprob * w[j][i-1];
			
			a[j][0][i] = (1<<(i-1)) * w[j][i] + a[j][0][i-1];
			//cout << j << " " << i << " " << a[j][0][i] << endl;
		}
	}
	
		for(int j=1; j<=n; j++){
			for(int k=j; k<=n; k++){
				for(int i=0; i<t; i++){
				if(i>=(1<<(n-j))) continue;
				a[i][j][k] = max(a[i*2 + 0][j-1][k] + a[i*2 + 1][j-1][j-1], a[i*2 + 1][j-1][k] + a[i*2 + 0][j-1][j-1]);
				//cout << i << " " << j << " " << k << " " << a[i][j][k] << endl;
			}
		}
	}
	cout << setprecision(12) << fixed << a[0][n][n] << endl;
}