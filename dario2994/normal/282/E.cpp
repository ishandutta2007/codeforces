#include <iostream>
#include <algorithm>
typedef unsigned long long ULL;
using namespace std;
const int f=40, M=100100;
int N, i, c, l, p[M][f];
ULL a[M], z[f], y[M], v, r;
ULL g(ULL x){
	int a=0, b=N+1;
	for(c=f-1;c>=0;c--){
		if(x&z[c]){
			if(a<p[a][c])b=min(b,p[a][c]);
		}
		else if(p[a][c]<b)a=p[a][c];
	}
	return x^y[a];
}
int main(){
	cin >> N;
	for(i=0;i<N;i++)cin >> a[i];
	for(i=N-1;i>=0;i--)y[i]=y[i+1]^a[i];
	sort(y,y+N+1);
	for(c=0;c<f;c++){
		l=N+1;
		z[c]=1LL<<c;
		for(int i=N;i>=0;i--){
			if(y[i]&z[c])l=i;
			p[i][c]=l;
		}
	}
	for(int i=0;i<N;i++)r=max(r,g(v)), v^=a[i];
	cout << r << "\n";
}