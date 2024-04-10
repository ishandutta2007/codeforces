#include <stdio.h>
typedef long long ll;
ll pos[200050];
ll t_pos[200050];
ll t_cnt[200050];
ll dis[200050]; // pos[i+1]-pos[i] = dis[i];
ll dis_sum[200050];
ll cnt[200050];
int N, M;
int st, rpcnt;
void input() {
	int i, t;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%lld", &t_pos[i]);
	scanf("%d", &M);
	for(i = 1; i <= M; i++) {
		scanf("%d", &t);
		t_cnt[t]++;
	}
	if(t_cnt[1] < t_cnt[N]) { //  cnt[1] >= cnt[N]
		for(i = 1; i <= N; i++) {
			cnt[i] = t_cnt[N+1-i];
			pos[i] = t_pos[N]+1-t_pos[N+1-i];
		}
	}
	else {
		for(i = 1; i <= N; i++) {
			cnt[i] = t_cnt[i];
			pos[i] = t_pos[i];
		}
	}
	for(i = 1; i <= N-1; i++) {
		dis[i] = pos[i+1]-pos[i];
		dis_sum[i] = dis_sum[i-1]+dis[i];
	}
	return;
}
void get_ans1() {
	ll ANS = (2*cnt[N]-1)*dis_sum[N-1];
	int i, k1 = -1, k2 = -1; // k1 : 1  , k2 : 2  
	for(i = 2; i <= N-1; i++) cnt[i] -= (2*cnt[N]-1);
	for(i = 2; i <= N-1; i++) {
		if(cnt[i] == 0) {
			k1 = i-1;
			break;
		}
		if(cnt[i] == 2) {
			k2 = i;
			break;
		}
	}
	for(i = N-1; i >= 2; i--) {
		if(cnt[i] == 0) {
			k2 = i+1;
			break;
		}
		if(cnt[i] == 2) {
			k1 = i;
			break;
		}
	}
	if(k1 == -1 && k2 == -1) {
		for(i = 2; i < N; i++) if(dis[i] != dis[1]) break;
		if(i != N) printf("-1");
		else printf("%lld", ANS+dis_sum[N-2]);
		return;
	}
	printf("%lld", ANS+dis_sum[k1-1]+dis_sum[N-1]-dis_sum[k2-1]);
	return;
}
void get_ans2() {
	int i, k1 = -1, k2 = -1; // k1 <= k2
	ll ANS = 2*cnt[N]*dis_sum[N-1];
	for(i = 2; i <= N-1; i++) cnt[i] -= cnt[N]*2;
	for(i = 2; i <= N-1; i++) {
		if(cnt[i] == 2) continue;
		if(cnt[i] == 1 && k1 == -1) k1 = i-1;
		if(cnt[i] == 0) {
			if(k1 == -1) k1 = i-1;
			if(k2 == -1) k2 = i-1;
			break;
		}
	}
	if(i == N) {
		if(k1 == -1) k1 = N-1;
		if(k2 == -1) k2 = N-1;
	}
	ANS += dis_sum[k1-1] + dis_sum[k2-1];
	printf("%lld", ANS);
	return;
}
void get_ans3() {
	int i, k1 = -1, k2 = -1; // k1 ~ k2 
	for(i = 2; i <= N-1; i++) {
		if(cnt[i] == 1 && k1 == -1) {
			k1 = i;
			continue;
		}
		if(cnt[i] == 0 && k1 != -1) {
			k2 = i-1;
			break;
		}
	}
	if(k2 == -1) k2 = N-1;
	printf("%lld", dis_sum[k2-1]-dis_sum[k1-1]);
	return;
}
int main() {
	//freopen("input.txt", "r", stdin);
	input();
	if(cnt[1] == cnt[N] && cnt[1] != 0) get_ans1();
	else if(cnt[1] != cnt[N]) get_ans2();
	else get_ans3();
	return 0;
}