#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
vector<string> ans;
int SN,BIT[100];
char num[10];
bool LESS(string a,string b){
	if(a.length()!=b.length())return a.length()<b.length();
	return a<b;
}
bool lead_0(string a){
	return a.length()>1&&a[0]=='0';
}
void putans(vector<string> &nums){
	string res;
	rep(k,nums.size())
	res+=nums[k]+'.';
	res.erase(res.end()-1);
	ans.push_back(res);
}
int SolveAns(string str,int NowPos,vector<string> &nums){
	int Now=nums.size();
	if(str.length()-NowPos<4-Now)return 0;
	if(NowPos==str.length()){
		putans(nums);
		return 1;
	}
	int res=0;
	if(!nums.empty()){
		string tmp=nums[Now-1]+str[NowPos];
		if(LESS(tmp,"256")&&!lead_0(tmp)){
			swap(nums[Now-1],tmp);
			res+=SolveAns(str,NowPos+1,nums);
			swap(nums[Now-1],tmp);
		}
	}
	if(nums.empty()||!nums[Now-1].empty()){
		string next;next.push_back(str[NowPos]);
		nums.push_back(next);
		res+=SolveAns(str,NowPos+1,nums);
		nums.erase(nums.end()-1);
	}
	return res;
}
int FindAns(string getN){
	string tmp=getN;
	reverse(tmp.begin(),tmp.end());
	vector<string> vec;
	int TMP=SolveAns(getN+tmp,0,vec);
	vec.clear();
	return TMP+SolveAns(getN+(tmp.substr(1)),0,vec);
}
int GetBck(string nowS,int Ns,int mask){
	if(Ns>6)return 0;
	if(6-BIT[mask]<SN-Ns)return 0;
	int res=0;
	if(mask+1==(1<<SN))res=FindAns(nowS);
	rep(k,SN)res+=GetBck(nowS+num[k],Ns+1,mask|(1<<k));
	return res;
}
int Solve(){
	return GetBck("",0,0);
}
int main(){
	cin>>SN;
	if(SN>6){
		cout<<0;
		return 0;
	}
	rep(k,SN)cin>>num[k];
	rep(k,1<<SN)BIT[k]=BIT[k>>1]+(k&1);
	cout<<Solve()<<endl;
	rep(k,ans.size())
	cout<<ans[k]<<endl;
	return 0;
}