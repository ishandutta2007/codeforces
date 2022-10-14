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
vector<int> ques[2];
pair<lli,int> questions[(int)2e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    sc(m);
    while(m--){
    	ques[0].clear();
    	ques[1].clear();
    	int n;
    	lli T,a,b;
    	sc(n,T,a,b);
    	rep(i,0,n){
			sc(questions[i].second);
    	}
    	rep(i,0,n){
    		sc(questions[i].first);
    		ques[questions[i].second].push_back(questions[i].first);
    	}
    	sort(questions,questions+n);
    	sort(ques[0].begin(),ques[0].end());
	    sort(ques[1].begin(),ques[1].end());
    	lli usedtime=0;
    	lli ans=0;
    	for(int i=0;i<n;i++){
			if(usedtime<questions[i].first){
				lli gettime=questions[i].first-usedtime-1;
				lli ama=sz(ques[0])-(upper_bound(ques[0].begin(),ques[0].end(),(i-1<0?(lli)-1:questions[i-1].first))-ques[0].begin());
				lli amb=sz(ques[1])-(upper_bound(ques[1].begin(),ques[1].end(),(i-1<0?(lli)-1:questions[i-1].first))-ques[1].begin());
				lli geta=min(ama,gettime/a);
				gettime-=geta*a;
				lli getb=min(amb,gettime/b);
				ans=max(ans,i+geta+getb);
			}
			usedtime+=(questions[i].second==0?a:b);
    	}
		if(usedtime<=T)ans=max(ans,(lli)n);
		prl(ans);
    }
    return 0;
}