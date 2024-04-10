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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
map<string,int> id;
bool isP[100005];
vector<int> Bs[100005];
int pr[100005],i[100005];
string getstr(int L){
	string ans="";
	getchar();
	rep(k,L)ans.push_back(getchar());
	return ans;
}
bool larger(int a,int b){return a>b;}
string rev(string s){
	string ans;
	for(int k=s.length()-1;k>=0;k--)ans.push_back(s[k]);
	return ans;
}
bool pal(string s){
	return s==rev(s);
}
int main(){
	int n,l,IS=0,cur,beau;
	scanf("%d%d",&n,&l);
	rep(k,n){
		string str=getstr(l);
		scanf("%d",&beau);
		if(id.find(str)!=id.end())cur=id[str];
		else{
			if(pal(str))isP[IS]=true;
			cur=id[str]=(IS++);
		}
		Bs[cur].push_back(beau);
	}
	for(map<string,int>::iterator it=id.begin();it!=id.end();it++)
	if(id.find(rev(it->first))!=id.end())pr[it->second]=id[rev(it->first)];
	else pr[it->second]=-1;
	rep(k,IS)sort(Bs[k].begin(),Bs[k].end(),larger);
	int bp=-1,sc=0;
	rep(k,IS){
		if(isP[k]){
			for(i[k]=0;i[k]<Bs[k].size();i[k]+=2){
				if(Bs[k][i[k]]<=0)break;
				if(i[k]==Bs[k].size()-1){
					bp=max(bp,Bs[k][i[k]]);
					i[k]++;
					break;
				}
				if(Bs[k][i[k]]+Bs[k][i[k]+1]<=0){
					bp=max(bp,Bs[k][i[k]]);
					break;
				}
				sc+=Bs[k][i[k]]+Bs[k][i[k]+1];
				if(Bs[k][i[k]+1]<0){
					bp=max(bp,-Bs[k][i[k]+1]);
					break;
				}
			}
		}else{
			if(pr[k]==-1)continue;
			rep(j,min(Bs[k].size(),Bs[pr[k]].size())){
				if(Bs[k][j]+Bs[pr[k]][j]>=0)sc+=Bs[k][j]+Bs[pr[k]][j];
				else break;
			}
			pr[pr[k]]=-1;
			pr[k]=-1;
		}
	}
	if(bp!=-1)sc+=bp;
	printf("%d",sc);
	return 0;
}