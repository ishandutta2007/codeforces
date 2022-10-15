
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=310000;
const int MAXK=18;
const ll INF = 1e15;
const ll MOD = 998244353;
 
ll dp[25][160]; // dp index, total
// 0 to 9 as digit
// -2 is no solution

ll ask(ll ind,ll tot){
	if(ind==-1&&tot!=0)return -2;
	if(tot==0)return 0;
	if(dp[ind][tot]!=-1)return dp[ind][tot];
	for(int i=0;i<10;++i){
		if(ind==0&&i==9)continue;
		if(ask(ind-1,tot-i)==-2)continue;
		else{
			return dp[ind][tot] = i;
		}
	}
	return dp[ind][tot]=-2;
}

string cons(ll ind,ll tot){
	if(ask(ind,tot) == -2)return "";
	string res;
	while(ind!=-1){
		// cout<<ask(ind,tot)<<'\n';
		res+=(char)('0'+ask(ind,tot));
		tot-=ask(ind,tot);
		ind--;
	}
	return res;
}

ll Q,a,b;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>Q;
	while(Q--){
		vector<string> answers;
		cin>>a>>b;++b;
		for(int unit=0;unit<=9;++unit){
			int lst=unit+b-1;
			if(lst>=10)continue;
			ll h=unit;
			ll value=0;
			for(int i=0;i<b;++i){
				value+=h;
				++h;
			}
			ll lefts=a-value;
			if(lefts<0||lefts%b!=0)continue;
			string A = cons(20,lefts/b);
			if(SZ(A) == 0)continue;
			A += (char)('0' + unit);
			// cout<<A<<'\n';
			answers.pb(A);
		}
		for(int overs=0;overs<b;++overs){
			ll unders = b-overs;
			ll unit = 10-unders;
			for(int trailing=0;trailing<20;++trailing){
				ll value = 0;
				ll h=9;
				for(int i=0;i<unders;++i){
					value+=h;
					--h;
				}
				h=0;
				for(int i=0;i<overs;++i){
					value+=h;
					++h;
				}
				value+=overs;
				value += 9*trailing*unders;
				ll lefts=a-value;
				if(lefts<0)continue;
				if(lefts%b!=0)continue;
				string A = cons(20,lefts/b);
				if(SZ(A) == 0)continue;
				for(int k=0;k<trailing;++k)A+='9';
				A += (char)('0' + unit);
				answers.pb(A);
			}
		}
		if(SZ(answers) == 0)cout<<"-1\n";
		else{
			for(auto &i:answers){
				reverse(ALL(i));
				while(SZ(i) > 20)i.pop_back();
				reverse(ALL(i));
			}
			sort(ALL(answers));
			string A = answers[0];
			reverse(ALL(A));
			while(SZ(A)&&A.back()=='0')A.pop_back();
			reverse(ALL(A));
			if(SZ(A)==0)A+='0';
			cout<<A<<'\n';
		}
	}
}