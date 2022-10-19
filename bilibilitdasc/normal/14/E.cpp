#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int a3[11]={0,14,0,0,0,0,0,0,0,0,0};
int a4[11]={0,22,0,0,0,0,0,0,0,0,0};
int a5[11]={0,16,70,0,0,0,0,0,0,0,0};
int a6[11]={0,6,232,0,0,0,0,0,0,0,0};
int a7[11]={0,1,380,353,0,0,0,0,0,0,0};
int a8[11]={0,0,396,1786,0,0,0,0,0,0,0};
int a9[11]={0,0,284,4500,1782,0,0,0,0,0,0};
int a10[11]={0,0,142,7414,12122,0,0,0,0,0,0};
int a11[11]={0,0,48,8849,41160,8997,0,0,0,0,0};
int a12[11]={0,0,10,8028,92226,76878,0,0,0,0,0};
int a13[11]={0,0,1,5658,152140,328222,45425,0,0,0,0};
int a14[11]={0,0,0,3112,195420,928494,467292,0,0,0,0};
int a15[11]={0,0,0,1322,201744,1947581,2402980,229347,0,0,0};
int a16[11]={0,0,0,422,170444,3213988,8205152,2758896,0,0,0};
int a17[11]={0,0,0,96,118912,4322956,20852648,16594160,1157954,0,0};
int a18[11]={0,0,0,14,68640,4846524,41920210,66357900,15946870,0,0};
int a19[11]={0,0,0,1,32632,4594423,69183464,197939352,109824208,5846414,0};
int a20[11]={0,0,0,0,12628,3715462,96046590,468541040,503245466,90700276,0};
//1234321234321234321
int n,t;
int main()
{
	cin>>n>>t;
	switch(n)
	{
		case 3:
			cout<<a3[t]<<endl;
			break;
		case 4:
			cout<<a4[t]<<endl;
			break;
		case 5:
			cout<<a5[t]<<endl;
			break;
		case 6:
			cout<<a6[t]<<endl;
			break;
		case 7:
			cout<<a7[t]<<endl;
			break;
		case 8:
			cout<<a8[t]<<endl;
			break;
		case 9:
			cout<<a9[t]<<endl;
			break;
		case 10:
			cout<<a10[t]<<endl;
			break;
		case 11:
			cout<<a11[t]<<endl;
			break;
		case 12:
			cout<<a12[t]<<endl;
			break;
		case 13:
			cout<<a13[t]<<endl;
			break;
		case 14:
			cout<<a14[t]<<endl;
			break;
		case 15:
			cout<<a15[t]<<endl;
			break;
		case 16:
			cout<<a16[t]<<endl;
			break;
		case 17:
			cout<<a17[t]<<endl;
			break;
		case 18:
			cout<<a18[t]<<endl;
			break;
		case 19:
			cout<<a19[t]<<endl;
			break;
		case 20:
			cout<<a20[t]<<endl;
			break;
		
	}
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/
//O(3^N),3