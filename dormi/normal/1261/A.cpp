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
    int t;
    sc(t);
    while(t--){
    	int n,k;
    	sc(n,k);
    	string a;
    	sc(a);
    	k-=1;
    	int l=0;
    	vector<pii> moves;
    	rep(i,0,k){
    		if(a[l]!='('){
    			int te=l;
    			while(a[te]!='(')te+=1;
    			moves.push_back({l,te});
    			reverse(a.begin()+l,a.begin()+te+1);
    		}
    		l+=1;
		    if(a[l]!=')') {
			    int te = l;
			    while (a[te] != ')')te += 1;
			    moves.push_back({l, te});
			    reverse(a.begin() + l, a.begin() + te + 1);
		    }
		    l+=1;
    	}
    	int half=(n-2*k)/2;
    	rep(i,0,half){
		    if(a[l]!='('){
			    int te=l;
			    while(a[te]!='(')te+=1;
			    moves.push_back({l,te});
			    reverse(a.begin()+l,a.begin()+te+1);
		    }
		    l+=1;
    	}
	    rep(i,0,half){
		    if(a[l]!=')'){
			    int te=l;
			    while(a[te]!=')')te+=1;
			    moves.push_back({l,te});
			    reverse(a.begin()+l,a.begin()+te+1);
		    }
		    l+=1;
	    }
	    prl(sz(moves));
    	for(pii x:moves)prl(x.first+1,x.second+1);
    }
    return 0;
}