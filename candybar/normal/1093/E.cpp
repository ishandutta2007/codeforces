#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
#define maxb 135
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int getint(){
  char c; int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}
int n,m;
int a[maxn],posa[maxn],b[maxn];
const int B = 1500;
int belong[maxn],num;
vector <int> buc[maxb];
void build(){
	num = n / B;
	if(n % B) num++;
	for(int i=1;i<=n;i++){
		belong[i] = (i - 1) / B + 1;
		buc[belong[i]].push_back(b[i]);
	}
	for(int i=1;i<=num;i++){
		sort(buc[i].begin(),buc[i].end());
	}
}
int query(int l,int r,int ql,int qr){//id in [l,r], val in [ql,qr]
	int res = 0;
	if(belong[l] == belong[r]){
		for(int i=l;i<=r;i++){
			if(ql <= b[i] && b[i] <= qr) res++;
		}
		return res;
	}
	for(int i=l;belong[i] == belong[l];i++){
		if(ql <= b[i] && b[i] <= qr) res++;
	}
	for(int i = belong[l] + 1;i < belong[r];i++){
		res += upper_bound(buc[i].begin(),buc[i].end(),qr) - lower_bound(buc[i].begin(),buc[i].end(),ql);
	}
	for(int i=r;belong[i] == belong[r];i--){
		if(ql <= b[i] && b[i] <= qr) res++;
	}
	return res;
}
void update(int pos,int x){//b[pos] to x.
	int id = belong[pos],i;
	for(i=0;i<(int)buc[id].size();i++) if(buc[id][i] == b[pos]) break;
	while(i > 0 && buc[id][i - 1] > x){
		buc[id][i] = buc[id][i - 1];
		i--;
	}
	while(i < (int)buc[id].size() - 1 && buc[id][i + 1] < x){
		buc[id][i] = buc[id][i + 1];
		i++;
	}
	buc[id][i] = b[pos] = x;
}
int main(){
	n = getint(), m = getint();
	for(int i=1;i<=n;i++){
		a[i] = getint();
		posa[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		b[i] = getint();
		b[i] = posa[b[i]];
	}
	build();
	while(m--){
		int fl;
		fl = getint();
		if(fl == 1){
			int la,ra,lb,rb;
			la = getint(), ra = getint(), lb = getint(), rb = getint();
			printf("%d\n",query(lb,rb,la,ra));
		}else{
			int x = getint(), y = getint();
			int tmp = b[x];
			update(x,b[y]);
			update(y,tmp);
		}
	}
	return 0;
}