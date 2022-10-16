#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=15;
int T,n,k,cnt,digit[MAXN],bucket[MAXN];
string ans;
string solve(int s){
	if(digit[cnt-s+1]==9)return "999999999999999999";
	memset(bucket,0,sizeof bucket);
	int num=0;
	string ret;ret.clear();
	per(i,cnt,cnt-s+2){
		if(!bucket[digit[i]])num++;
		bucket[digit[i]]++;
		ret+=('0'+digit[i]);
	}
	if(num>k)return "999999999999999";
	if(num==k){
		int flag=0;
		rep(j,digit[cnt-s+1]+1,9){
			if(bucket[j]){
				flag=1;
				ret+=('0'+j);
				break;
			}
		}
		if(!flag)return "9999999999999999999";
	}else{
		if(bucket[digit[cnt-s+1]+1]==0)num++;
		bucket[digit[cnt-s+1]+1]++;
		ret+=('0'+digit[cnt-s+1]+1);
	}
	if(num==k){
		rep(j,0,9){
			if(bucket[j]){
				rep(i,1,cnt-s)ret+=('0'+j);
				return ret;
			}
		}
	}
	rep(i,1,cnt-s)ret+='0';
	return ret;
}
int main(){
	cin>>T;
	while(T--){
		ans="99999999999999999";
		cin>>n>>k;memset(bucket,0,sizeof bucket);
		ll num=n;cnt=0;ll tot=0;
		while(num){
			digit[++cnt]=num%10;
			num/=10;
			if(!bucket[digit[cnt]])tot++;
			bucket[digit[cnt]]++;
		}
		if(tot<=k){
			ans.clear();
			per(i,cnt,1){
				ans+=('0'+digit[i]);
			}
		}
		rep(i,1,cnt){
			ans=min(ans,solve(i));
		}
		cout<<ans<<endl;
	}

	return 0;
}