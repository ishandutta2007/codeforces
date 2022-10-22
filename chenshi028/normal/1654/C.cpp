#include<cstdio>
#include<set>
using namespace std;
int T,n,a,z;long long w,x,y;multiset<long long> s1,s2;
inline void slv(){
	for(scanf("%d",&n),z=2*n;n--;s1.insert(a)) scanf("%d",&a),w+=a;
	for(s2.insert(w);--z;s2.erase(s2.find(x)))
		if(s1.find(x=*s2.begin())!=s1.end()) s1.erase(s1.find(x));
		else s2.insert(x/2),s2.insert((x+1)/2);
	printf(s2.empty()?"YES\n":"NO\n");
}
int main(){
	for(scanf("%d",&T);T--;s1.clear(),s2.clear(),w=0) slv();
	return 0;
}