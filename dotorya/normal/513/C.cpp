#include <stdio.h>

class Bid {
public:
	Bid() { Bid(0,0); }
	Bid(int a, int b) {L = a, R = b;}
	int L, R;
	double prob(int x) {
		if(x < L) return 0;
		if(x >= R) return 1;
		return 1.0*(x-L+1)/(R-L+1);
	}
} d[7];

double win_prob[32][10050];
double win_prob_sum[32][10050];
double win_exp[32][10050];
double win_exp_sum[32][10050];
int main() {
	int i, N, j, k;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d %d", &d[i].L, &d[i].R);

	// same win prob.
	for(i = 1; i <= 31; i++) {
		for(j = 10000; j >= 1; j--) {
			int t = i;
			double p = 1;
			for(k = 1; k <= N; k++) {
				if(t%2 == 1) p *= d[k].prob(j)-d[k].prob(j-1);
				t /= 2;
			}
			win_prob[i][j] = p;
			win_exp[i][j] = p*j;
			win_prob_sum[i][j] = win_prob_sum[i][j+1]+win_prob[i][j];
			win_exp_sum[i][j] = win_exp[i][j]+win_exp_sum[i][j+1];
		}
	}

	// ANS
	
	double ANS = 0;
	for(i = 1; i <= 10000; i++) {
		for(j = 1; j < (1 << N)-1; j++) {
			int t = j;
			double p = 1;
			for(k = 1; k <= N; k++) {
				if(t % 2 == 0) p *= d[k].prob(i);
				t /= 2;
			}
			double p2 = 1;
			t = j;
			for(k = 1; k <= N; k++) {
				if(t % 2 == 0) p2 *= d[k].prob(i-1);
				t /= 2;
			}
			p -= p2, t = j;
			if(j == 1 || j == 2 || j == 4 || j == 8 || j == 16) {
				p *= win_prob_sum[j][i+1];
				ANS += p*i;
			}
			else ANS += p*win_exp_sum[j][i+1];
		}
	}
	ANS += win_exp_sum[31][1];
	printf("%.20lf", ANS);
	return 0;
}