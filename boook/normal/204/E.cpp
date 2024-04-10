#include <bits/stdc++.h>
using namespace std;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int int_fast64_t
#define MAX 200900
#define INF 0x3f3f3f3f

int n , k , pos , id[MAX] , siz[MAX] , ans[MAX];
int N , sa[MAX] , rk[MAX] , lcp[MAX] , sp[MAX][20] , one[MAX];
int gap , tma[MAX] , chr[MAX];
string s;
int cmp(int i , int j){
	if(chr[i] != chr[j]) return chr[i] < chr[j];
	i += gap , j += gap;
	return (i < N && j < N) ? chr[i] < chr[j] : i > j;
}
void getsa(){
	REP(i , 0 , N) sa[i] = i , chr[i] = s[i];
	for(gap = 1 ; tma[N - 1] != N - 1 ; gap <<= 1){
		stable_sort(sa , sa + N , cmp);
		REP(i , 1 , N) tma[i] = tma[i - 1] + cmp(sa[i - 1] , sa[i]);
		REP(i , 0 , N) chr[sa[i]] = tma[i];
	}
}
void getlcp(int tmp = 0){
	REP(i , 0 , N) rk[sa[i]] = i;
	REP(i , 0 , N) if(rk[i]){
		if(tmp) tmp --;
		int res = sa[rk[i] - 1];
		while(tmp + res < N && tmp + i < N && s[tmp + res] == s[tmp + i]) tmp ++;
		lcp[rk[i]] = min(min(siz[res] , siz[i]) , tmp);
	}
}
int query(int l , int r){
	if(l == r) return N - sa[l];
	int tmp = one[r - l];
	return min(sp[l + 1][tmp] , sp[r - (1 << tmp) + 1][tmp]);
}
void getsp(){
	REP(i , 2 , N) one[i] = one[i >> 1] + 1;
	REP(i , 0 , N) sp[i][0] = lcp[i];
	REP(j , 1 , 20) REP(i , 0 , N){
		int to = i + (1 << (j - 1));
		if(to < N) sp[i][j] = min(sp[i][j - 1] , sp[to][j - 1]);
		else break;
	}
}
int inq[MAX] , inqnum = 0 , okr[MAX];
void pushqueue(int idx , int val){
	int now = id[sa[idx]];
	inqnum += inq[now] == 0;
	inq[now] += val;
	inqnum -= inq[now] == 0;
}
void solve(int r = 0){
	REP(l , 0 , N){
		while(r < N && inqnum < k) pushqueue(r ++ , 1);
		okr[l] = inqnum == k ? r - 1 : INF;
		pushqueue(l , -1);
	}
	REP(i , 0 , N){
		int val = 0;
		RREP(ii , 17 , 0){
			int goal = val + (1 << ii);
			if(goal <= siz[sa[i]]){
				int ll = i , rr = i;
				RREP(jj , 17 , 0){
					int tol = ll - (1 << jj) , tor = rr + (1 << jj);
					if(tol >= 0 && query(tol , i) >= goal) ll = tol;
					if(tor <  N && query(i , tor) >= goal) rr = tor;
				}
				if(okr[ll] <= rr) val = goal;
			}
		}
		ans[id[sa[i]]] += val;
	}	
}
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1){
		string in; cin >> in , s += in;
		REP(j , 0 , in.size()){
			siz[pos] = in.size() - j;
			id[pos ++] = i;
		}
		s += "@" , pos ++;
	}
	N = s.size();
	getsa() , getlcp() , getsp() , solve();
	REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}