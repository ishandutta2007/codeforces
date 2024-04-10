#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+1e6;
ll a[MAX_N],b[MAX_N],t[MAX_N],e[MAX_N];
vector<ll> key;
vector<ll> g1[MAX_N],g2[MAX_N];
multiset<ll> s;
int main(){
    int n; scanf("%d",&n);
    key.push_back(0);
    for(int i=1;i<=n;++i){
   	scanf("%lld%lld%lld",&a[i],&b[i],&t[i]);
    	key.push_back(a[i]+t[i]);
    	key.push_back(b[i]+1);
    }
    sort(key.begin(),key.end());
    key.erase(unique(key.begin(),key.end()),key.end());
    for(int i=1;i<=n;++i){
    	int pos1=lower_bound(key.begin(),key.end(),a[i]+t[i])-key.begin()+1;
    	int pos2=lower_bound(key.begin(),key.end(),b[i]+1)-key.begin()+1;
    	g1[pos1].push_back(t[i]);
    	g2[pos2].push_back(t[i]);
    }
    s.insert((ll)8e18);
    for(int i=1;i<key.size();++i){
    	for(auto x:g1[i]) s.insert(x);
    	for(auto x:g2[i]) s.erase(s.find(x));
		e[i]=*s.begin();
  //  	printf("(%lld %lld %lld)",e[i],key[i-1],key[i]);
    }
    ll ans=0,len=0;
    for(int i=1;i<key.size();++i){
//		printf("<%lld %lld>",ans,len);
    	if(min(len,e[i])+key[i]-key[i-1]-1>=e[i]){
    		len=min(len,e[i])+key[i]-key[i-1]-1;
    		ans+=len/e[i];
    		len=len%e[i]+1;
    	}else len+=key[i]-key[i-1];
    }
    printf("%lld\n",ans);
    return 0;
}