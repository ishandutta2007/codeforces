#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int Hy,Ay,Dy;
int Hm,Am,Dm;
int h,a,d;

int main() {
	scanf("%d%d%d%d%d%d%d%d%d",&Hy,&Ay,&Dy,&Hm,&Am,&Dm,&h,&a,&d);
	int min_cost = 0x7fffffff;
	for(int k = 1; k <= 300; ++k) {
		int a_y = max(Ay,(Hm + k-1)/k + Dm);
		for(int d_y = Dy; d_y <= 100; ++d_y) {
			int h_y = max(1+k*max(0,Am-d_y),Hy);
			int cost = h*(h_y-Hy) + a*(a_y-Ay) + d*(d_y-Dy);
			min_cost = min(min_cost,cost);
		}
	}
	printf("%d\n",min_cost);
	return 0;
}