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
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}

string s;
void Read(){
	cin >> s;	
}
int F(char now){ return (now >= '0' && now <= '9'); }
void G(){
	int a = 0 , b = 0;
	REP(i , s.size()){
		if(F(s[i])) a = a * 10 + s[i] - '0';
		else b = b * 26 + s[i] - 'A' + 1;
	}
	cout << "R" << a << "C" << b << endl;
}
void H(){
	int a[2] , tmp = 0;
	a[0] = a[1] = 0;
	REPNM(i , 1 , s.size()){
		if(!F(s[i])) tmp ++;
		else a[tmp] = a[tmp] * 10 + s[i] - '0';
	}
	stack<int> sk;
	while(a[1]){
		if(a[1] % 26 == 0) a[1] -= 26 , sk.push(26);
		else sk.push(a[1] % 26);
		a[1] /= 26;
	}
	while(sk.size()) cout << char('A' + sk.top() - 1) , sk.pop();
	cout << a[0] << endl;
}
void Solve(){
	int sum = 0;
	REPNM(i , 1 , s.size()){
		if(F(s[i]) != F(s[i - 1]) && F(s[i])) sum ++;
	}
	if(sum == 1) G();
	else H();
}

int main(){
	IOS;
	Pre();

	int _ = 1;
	cin >> _;
	
	while(_--){
		Read();
		Init();
		Solve();
	}
    return 0;
}