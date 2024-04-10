#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define LL  long long int
#define PII pair<int , int>
#define PLL pair< LL , LL >
#define VI  vector<int> 
#define VLL vector<LL> 
#define VPII vector<PII>
#define VPLL vector<PLL>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string q[] = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
string w[] = {"ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"};
string e[] = {"twenty" , "thirty" , "forty" , "fifty" , "sixty" , "seventy" , "eighty" , "ninety"};
int32_t main(){
    int n;
    cin >> n;
    if(n <= 9) cout << q[n] << endl;
    else if(n <= 19) cout << w[n - 10];
    else {
        int tmp = n / 10;
        cout << e[tmp - 2];
        if(n % 10 != 0)
            cout << "-" << q[n % 10] << endl;
    }

    
    return 0;
}