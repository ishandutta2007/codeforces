#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cout<<"a"<<endl;
	int in;
	sc(in);
	if(in==0||in==-1)return 0;
	int len=in+1;
	if(len>300){
		len=300;
		string toprint;
		toprint.resize(len);
		rep(i, 0, len) {
			toprint[i] = 'b';
		}
		cout<<toprint<<endl;
		sc(in);
		assert(in==0);
		return 0;
	}
	string toprint;
	toprint.resize(len);
	rep(i, 0, len) {
		toprint[i] = 'a';
	}
	cout<<toprint<<endl;
	sc(in);
	if(in==0||in==-1)return 0;
	if(in==len){
		len-=1;
		string te;
		te.resize(len);
		rep(i, 0, len) {
			te[i] = 'b';
		}
		cout<<te<<endl;
		sc(in);
		assert(in==0);
		return 0;
	}
	int dist=in;
	int bcnt=in;
	int acnt=len-in;
	string ans;
	ans.resize(len);
	rep(i,0,len-1){
		toprint[i]='b';
		cout<<toprint<<endl;
		sc(in);
		if(in==0||in==-1)return 0;
		if(dist>in){
			ans[i]='b';
			bcnt--;
		}
		else{
			ans[i]='a';
			acnt--;
		}
		toprint[i]='a';
	}
	if(acnt)ans[len-1]='a';
	else ans[len-1]='b';
	cout<<ans<<endl;
    return 0;
}