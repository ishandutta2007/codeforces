#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
char ch[3];
ll op(vector<ll> &v){
	ll res=1e18;
	if(v.size()==1){
		return v[0];
	}else{
		ll k=(4-v.size())*2;
		for(ll i=0;i<v.size()-1;i++){
			for(ll j=i+1;j<v.size();j++){
				vector<ll> vv;
				if(ch[k]=='+'){
					vv.push_back(v[i]+v[j]);
				}else{
					vv.push_back(v[i]*v[j]);
				}
				for(ll kk=0;kk<v.size();kk++){
					if(kk!=i && kk!=j){
						vv.push_back(v[kk]);
					}
				}
				ll kk=op(vv);
				if(kk<res){
					res=kk;
				}
			}		
		}
	}
	return res;
}
int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	gets(ch);
	gets(ch);
	vector<ll> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	ll ans=op(v);
	cout<<ans;
	return 0;
}