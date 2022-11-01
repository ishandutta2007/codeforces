#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int mod = 998244353;

int ww[(1 << 24)], *e = ww + (1 << 23);

int qpow(int b, int x){
	int ret = 1;
	
	while(x){
		if(x & 1){
			ret = 1ll * ret * b % mod;
		}
		
		b = 1ll * b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

int DFT(vector <int> &A, int N, int C){
	int w, l, r;
	vector <int> B(N);
	int i, j, k;
	
	for(i=N;i>1;i>>=1,swap(A, B)){
		for(j=0;j<N;j+=i){
			for(k=0;k<i;k+=2){
				B[j + (k >> 1)] = A[j + k];
				B[j + (k >> 1) + (i >> 1)] = A[j + k + 1];
			}
		}
	}
	
	for(i=2;i<=N;i<<=1,swap(A, B)){
		for(w=0,k=0;k<(i>>1);k++,w+=N/i*C){
			for(j=0;j<N;j+=i){
				l = A[j + k], r = 1ll * e[w] * A[j + (i >> 1) + k] % mod;
				B[j + k] = ((l + r >= mod) ? l + r - mod : l + r);
				B[j + (i >> 1) + k] = ((l - r < 0) ? l - r + mod : l - r);
			}
		}
	}
	
	return 0;
}

vector <int> NTT(vector <int> &A, vector <int> &B){
	int AZ = A.size();
	int BZ = B.size();
	int N;
	for(N=1;N<AZ+BZ;N<<=1);
	vector <int> AN(N);
	vector <int> BN(N);
	copy(A.begin(), A.end(), AN.begin());
	copy(B.begin(), B.end(), BN.begin());
	
	e[0] = e[-N] = 1;e[1] = e[1 - N] = qpow(3, (mod - 1) / N);
	for(int i=2;i<N;i++)e[i - N] = e[i] = 1ll * e[i - 1] * e[1] % mod;
	DFT(AN, N, 1);DFT(BN, N, 1);
	for(int i=0;i<N;i++)AN[i] = 1ll * AN[i] * BN[i] % mod;
	DFT(AN, N, -1);
	int NI = qpow(N, mod - 2);
	for(int i=0;i<N;i++)AN[i] = 1ll * AN[i] * NI % mod;
	
	return AN;
}

vector <int> NTT2(vector <int> &A){
	int AZ = A.size();
	int N;
	for(N=1;N<AZ+AZ;N<<=1);
	vector <int> AN(N);
	copy(A.begin(), A.end(), AN.begin());
	
	e[0] = e[-N] = 1;e[1] = e[1 - N] = qpow(3, (mod - 1) / N);
	for(int i=2;i<N;i++)e[i - N] = e[i] = 1ll * e[i - 1] * e[1] % mod;
	DFT(AN, N, 1);
	for(int i=0;i<N;i++)AN[i] = 1ll * AN[i] * AN[i] % mod;
	DFT(AN, N, -1);
	int NI = qpow(N, mod - 2);
	for(int i=0;i<N;i++)AN[i] = 1ll * AN[i] * NI % mod;
	
	return AN;
}

int n, m;
vector <int> a;
vector <int> b;

int main(){
	int i, j;
	int x;
	int ans = 0;
	
	scanf("%d%d", &n, &m);
	
	for(i=0;i<10;i++){
		a.push_back(0);
	}
	
	for(i=1;i<=m;i++){
		scanf("%d", &x);
		a[x] = 1;
	}
	
	x = n / 2 - 1;
	
	b = a;
	
	while(x){
		if(x & 1){
			b = NTT(b, a);
			for(i=b.size()-1;i>=0;i--){
				if(!b[i]){
					b.pop_back();
				}else{
					break;
				}
			}
		}
		
		a = NTT2(a);
		
		for(i=a.size()-1;i>=0;i--){
			if(!a[i]){
				a.pop_back();
			}else{
				break;
			}
		}
		
		x >>= 1;
	}
	
	for(i=0;i<b.size();i++){
		ans = (ans + 1ll * b[i] * b[i] % mod) % mod;
	}
	
	printf("%d\n", ans);
	
	return 0;
}