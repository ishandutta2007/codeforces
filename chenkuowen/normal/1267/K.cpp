#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		ll n; scanf("%lld",&n);
		vector<int> s; s.clear();
		map<int,int> mp;
		for(int i=2;n>0;++i){
			s.push_back(n%i);
			n/=i;
		}
		sort(s.begin(),s.end());
	//	for(int i=0;i<s.size();++i) printf("(%d)",s[i]); puts("");
//		printf("<%d>",(int)s.size());
		ll f[2]={1,0},pw=1;
		int cnt=0;
		for(int i=(int)s.size()-1;i>=0;--i){
			if(i==(int)s.size()-1||s[i]!=s[i+1]) cnt=1;
			else cnt++;
			pw*=cnt;
			if(s[i]>0){
				int t1=(int)s.size()+1-s[i],t2=(int)s.size()-i;
		//		printf("<%d>",t1-t2);
				f[1]=f[1]*(t1-t2+1)+f[0];
				f[0]=f[0]*(t1-t2);
			}else{
				int t1=(int)s.size()-s[i],t2=(int)s.size()-i;
		//		printf("<%d>",t1-t2);
				f[1]=f[1]*(t1-t2+1);
				f[0]=f[0]*(t1-t2);
			}
		//	printf("(%lld %lld)",f[0],f[1]);
		}
		printf("%lld\n",(f[0]+f[1])/pw-1);
	}
	return 0;
}