#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie(0) , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 1000900
#define MAXN 1090
#define INF 0x3f3f3f3f
#define debug 1

string s;
int con[MAX] , N , n;
int box[MAXN][MAXN] , rr[MAXN][MAXN] , tb[MAXN] , use[MAX];
stack<int> cc;
void solveinit(){
    REP(i , s.size()){
        if(s[i] == '(') cc.push(i);
        else {
            if(cc.empty()) con[i] = -1;
            else con[i] = cc.top() , con[cc.top()] = i , cc.pop();
        }
    }
    while(cc.size()) con[cc.top()] = -1 , cc.pop();

    REP(i , s.size()){
        if(con[i] == -1 || i > con[i]) continue;
        int a = i / N , b = con[i] / N;
        box[max(a , b)][min(a , b)] ++;
    }
    int sum = 0;
    REP(i , N + 3){
        REP(j , i + 1) tb[j] += box[i][j] , sum += box[i][j];
        int cnt = 0;
        REP(j , i + 1){
            rr[i][j] = sum - cnt;
            cnt += tb[j];
        }
    }
}
int Find(int l , int r ,int  times){
	int rel = l;
	int ans = 0;
	while(l <= r){
		if(l % N == 0 && l + N <= r){
			int tma = l / N , tmb;
			while(l + N <= r) l += N;
			tmb = l / N;
			ans += rr[tmb - 1][tma];
		}
		else {
			if(con[l] != -1 && con[l] <= r && con[l] >= rel && use[l] != times
				&& use[con[l]] != times)
				ans++ , use[l] = use[con[l]] = times;
	     	l++;
	     }
	}
    return ans;
}
int main(){
	IOS;
    while(cin >> s){
        n = s.size();
        N = sqrt(n);
        solveinit();
        int q , w , e;
        cin >> q;
        REP(i , q){
            cin >> w >> e;
            cout << Find(w - 1 , e - 1 , i + 1) * 2 << endl;
        }
    }
    return 0;
}