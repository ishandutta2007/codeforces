#include<bits/stdc++.h>
using namespace std;

const long long lbt=1000000007;
const int maxn=100005;

struct seg{
	long long l,r;
};


int n;
long long x,y;
seg s[maxn];
multiset<int> st;

long long ans=0;
void s1(int i){
	ans+=(s[i].r-s[i].l)*y+x;
	ans%=lbt;
	st.insert(s[i].r);
}
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		cin>>s[i].l>>s[i].r; 
	}		
	sort(s+1,s+1+n,[](seg a,seg b){
		return a.l<b.l;
	});	
	for(int i=1;i<=n;i++){
		if(st.empty()){
			s1(i);
		}else{
			set<int>::iterator it=st.lower_bound(s[i].l);
			if(it==st.begin()){
				s1(i);
			}else{
				it--;
				if((s[i].r-(*it))*y<=(s[i].r-s[i].l)*y+x){
					ans+=(s[i].r-(*it))*y;
					ans%=lbt;
					st.erase(it);
					st.insert(s[i].r);
				} else s1(i); 
			}
		}
	}
	cout<<ans;
    return 0;
}