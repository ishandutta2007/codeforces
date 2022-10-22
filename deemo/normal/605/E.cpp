//I race the dawn for you..

#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n;
bool mark[MAXN];
ld p[MAXN][MAXN], x[MAXN], rem[MAXN], e[MAXN];

ld get(int v){return (x[v]+rem[v])/(1. - rem[v]);}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			int temp;	scanf("%d", &temp);
			p[i][j] = temp/ 100.;
		}

	for (int i = 0; i < n; i++)	rem[i] = 1., e[i] = 1e18;
	for (int c = 0; c < n; c++){
		pair<int, ld>	mn(-1, 0);
		if (c == 0)
			mn = {n-1, 0};
		else{
			for (int i = 0; i < n; i++)
				if (!mark[i] && rem[i] < 1.){
					ld temp = get(i);
					//printf("%d  %.10lf\n", i, temp);
					if (mn.F == -1 || mn.S > temp)
						mn = {i, temp};
				}
		}

		mark[mn.F] = 1;
		e[mn.F] = mn.S;
		for (int i = 0; i < n; i++)
			if (!mark[i]){
				x[i] += p[i][mn.F] * rem[i] * (mn.S + 1.);
				rem[i] *= 1. - p[i][mn.F];
			}
	}

	printf("%.14lf\n", (double)e[0]);
	return 0;
}