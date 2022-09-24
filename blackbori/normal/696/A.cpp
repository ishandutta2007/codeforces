#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

struct pp{
	LL a,b,c,k;
}D[1010];

LL n,p;
vector <LL> aa,bb,K[1010];

LL lmx(LL ma,LL mb)
{
	return ma>mb?ma:mb;
}

LL par(LL a,LL b)
{
	LL c,i;
	aa.clear(), bb.clear();
	while(a) aa.push_back(a%2),a/=2;
	while(b) bb.push_back(b%2),b/=2;
	
	c=0;
	while(aa.size()&&bb.size()&&aa.back()==bb.back()){
		c=c*2+aa.back();
		aa.pop_back(), bb.pop_back();
	}
	
	return c;
}

LL Count(LL k)
{
	LL a=0,b=0,s=0;
	for(a=0;a<aa.size();a++){
		while(K[k][b] < aa[a] && b+1 < K[k].size()) b++;
		if(K[k][b] == aa[a]) s++;
	}
	
	return s;
}

int main()
{
	scanf("%I64d",&n);
	
	LL i,j,a,b,c,s;
	
	for(i=0;i<n;i++){
		scanf("%I64d",&a);
		if(a==1){
			scanf("%I64d %I64d %I64d",&a,&b,&D[++p].k);
			D[p].a=a, D[p].b=b;
			D[p].c=c=par(a,b);
			K[p].push_back(c);
			while(a!=c) K[p].push_back(a), a/=2;
			while(b!=c) K[p].push_back(b), b/=2;
			
			sort(K[p].begin(),K[p].end());
		}
		else{
			scanf("%I64d %I64d",&a,&b);
			c=par(a,b);

			aa.clear();
			aa.push_back(c);
			while(a!=c) aa.push_back(a), a/=2;
			while(b!=c) aa.push_back(b), b/=2;
			
			sort(aa.begin(),aa.end());
			
			s=0;
			for(j=1;j<=p;j++){
				s+=lmx(0,Count(j)-1)*D[j].k;
			}
			printf("%I64d\n",s);
		}
	}
	
	return 0;
}