#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 300003;
int n, s[N], t[N], d[N], id[N], ans1[N], ans2[N], ans3[N], m;
LL tmp;
inline bool cmp(int a, int b){return s[a] < s[b];}
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++) scanf("%d", s + i), id[i] = i;
	for(Rint i = 1;i <= n;i ++) scanf("%d", t + i);
	sort(id + 1, id + n + 1, cmp);
	sort(s + 1, s + n + 1); sort(t + 1, t + n + 1);
	for(Rint i = 1;i <= n;i ++) d[i] = t[i] - s[i], tmp += d[i];
	if(tmp != 0){
		puts("NO");
		return 0;
	}
	for(Rint i = 1, p = 1;i <= n;i ++){
		if(d[i] == 0) continue;
		if(d[i] < 0){
			puts("NO");
			return 0;
		}
		while(d[i] > 0){
			while(d[p] >= 0) ++ p;
			int dis = min(d[i], min(-d[p], (s[p] - s[i]) >> 1));
			d[i] -= dis;
			d[p] += dis;
			ans1[++ m] = id[i];
			ans2[m] = id[p];
			ans3[m] = dis;
		}
	}
	puts("YES");
	printf("%d\n", m);
	for(Rint i = 1;i <= m;i ++) printf("%d %d %d\n", ans1[i], ans2[i], ans3[i]);
}