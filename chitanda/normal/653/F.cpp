//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 500100;
int n;
int lg[maxn], M[maxn][20], cal[maxn][20], s[maxn];
char str[maxn];
int c[maxn], t1[maxn], sa[maxn], t2[maxn], height[maxn], ran[maxn];
ll ans;

void init(){
	int i,*x=t1,*y=t2,m=2000;    
	memset(c,0,sizeof(c)); c[0]=1;
	FOR(i,1,n) c[x[i]=str[i]]++; 
	FOR(i,1,m) c[i]+=c[i-1];    
	ROF(i,n,1) sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1){
		int p=1;
		FOR(i,n-k+1,n) y[p++]=i;
		FOR(i,1,n) if (sa[i]>k) y[p++]=sa[i]-k;
		memset(c,0,sizeof(c)); c[0]=1; 
		FOR(i,1,n) c[x[y[i]]]++;
		FOR(i,1,m) c[i]+=c[i-1];
		ROF(i,n,1) sa[--c[x[y[i]]]]=y[i]; 
		swap(x,y);
		p=2; x[sa[1]]=1;
		for(i=2;i<=n;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if (p>n) break; m=p;
	}
	FOR(i,1,n) ran[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){ 
		if(k)k--;int j=sa[ran[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[ran[i]]=k;
	}
}

int RMQ(int l, int r){
	int k = lg[r - l + 1];
	return min(M[l][k], M[r - (1 << k) + 1][k]);
}

int nRMQ(int l, int r, int v){
	int ans = 0;
	ROF(i, lg[r - l + 1], 1)
		if(l + (1 << i) - 1 <= r){
			ans += (M[l][i] == v) * cal[l][i];
			l += (1 << i);
		}
	return ans;
}

int query(int l, int r){
	if(l > r) return 0;
	int lt = 0, rt = r - l + 1;
	while(lt + 1 < rt){
		int mid = (lt + rt) >> 1;
		if(RMQ(l, l + mid) >= s[l - 1]) lt = mid;
		else rt = mid;
	}
	if(RMQ(l, l + lt) == s[l - 1]) return nRMQ(l, l + lt, s[l - 1]);
	else return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	scanf("%s", str + 1);
	FOR(i, 1, n){
		s[i] = s[i - 1] + (str[i] == '(' ? 1 : -1);
		M[i][0] = s[i]; cal[i][0] = 1;
	}
	FOR(i, 0, 18) lg[1 << i] = i;
	FOR(i, 1, n) lg[i] = max(lg[i], lg[i - 1]);
	FOR(k, 1, 18)
		FOR(i, 1, n - (1 << k) + 1){
		M[i][k] = min(M[i][k - 1], M[i + (1 << (k - 1))][k - 1]);
		if(M[i][k - 1] == M[i][k]) cal[i][k] += cal[i][k - 1];
		if(M[i + (1 << (k - 1))][k - 1] == M[i][k]) cal[i][k] += cal[i + (1 << (k - 1))][k - 1];
	}
	init();
	FOR(i, 1, n)
		ans += query(sa[i], n) - query(sa[i], sa[i] + height[i] - 1);
	cout << ans;
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/