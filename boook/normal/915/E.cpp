/*input
4
6
1 2 1
3 4 1
2 3 2
1 3 2
2 4 1
1 4 2
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300090
#define INF 0x3f3f3f3f

int sum[MAX * 63] , ls[MAX * 63] , rs[MAX * 63] , po = 2;
char tag[MAX * 63];

int n , m , ql , qr , k;
void Push(int now , int l , int r){
	if(l != r && tag[now] != 0){
		int mid = ((l + r) >> 1);
		if(ls[now] == 0) ls[now] = po ++;
		if(rs[now] == 0) rs[now] = po ++;

		sum[ls[now]] = ((int)tag[now] == 1) * ((mid + 0) - l + 1);
		sum[rs[now]] = ((int)tag[now] == 1) * (r - (mid + 1) + 1);

		tag[ls[now]] = tag[now];
		tag[rs[now]] = tag[now];
		tag[now] = 0;
	}
}
void update(int now , int l , int r){
	int mid = ((l + r) >> 1);
	if(ql <= l && r <= qr){
		sum[now] = (k == 1) * (r - l + 1);
		tag[now] = k;
	}
	else {
		Push(now , l , r);
		if(ql <= mid + 0){
			if(ls[now] == 0) ls[now] = po ++;
			update(ls[now] , l , mid + 0);
		}
		if(mid + 1 <= qr){
			if(rs[now] == 0) rs[now] = po ++;
			update(rs[now] , mid + 1 , r);
		}
		sum[now] = sum[ls[now]] + sum[rs[now]];
	}
}
inline int rit(){
	int res = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		res = (res << 1) + (res << 3) + c - '0';
		c = getchar();
	}
	return res;
}
int32_t main(){
	n = rit() , m = rit();
	tag[1] = 1;
	sum[1] = n;
	REP(i , 1 , m + 1){
		ql = rit() , qr = rit() , k = 3 - rit();
		update(1 , 1 , n);
		printf("%d\n", sum[1]);
	}
    return 0;
}