#include <bits/stdc++.h>
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

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int l;
    string a;
    sc(l,a);
    if((int)a.size()%l==0){
		int am=(int)a.size()/l;
		string rep=a.substr(0,l);
		string ans=rep;
		for(int i=1;i<am;i++){
			ans+=rep;
		}
		if(ans<=a) {
			rep = "0" + rep;
			int loc = (int) rep.size() - 1;
			while (rep[loc] == '9') {
				rep[loc--] = '0';
			}
			rep[loc] = (char) ((int) rep[loc] + 1);
			if (rep[0] == '0') {
				rep = rep.substr(1);
			}
			else if(rep[0]=='1'){
				rep.resize(rep.size()-1);
				am+=1;
			}
			ans = rep;
			for (int i = 1; i < am; i++) {
				ans += rep;
			}
		}
		pr(ans);
    }
    else{
    	int am=(int)a.size()/l+1;
    	string top="1";
    	for(int i=1;i<l;i++)top+="0";
    	for(int i=0;i<am;i++){
			pr(top);
    	}
    }
    return 0;
}