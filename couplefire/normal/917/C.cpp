#include <bits/stdc++.h>
using namespace std;
const int N = 1<<8;
int x,n,k,q,at[N],c[25],p[25],w[25];
vector<int>v;
map<int,int>mp;
struct matrix{
	long long mat[N][N];
	matrix(){
		for(int i = 0;i < v.size();i++)
			for(int j = 0;j < v.size();j++)
				mat[i][j] = 1e18;
	}
	void I(){for(int i = 0;i < v.size();i++)mat[i][i] = 0;}
	matrix operator*(const matrix &a)const{
		matrix ret;
		for(int i = 0;i < v.size();i++)
			for(int j = 0;j < v.size();j++)
				for(int k = 0;k < v.size();k++)
					ret.mat[i][k] = min(ret.mat[i][k],mat[i][j] + a.mat[j][k]);
	    return ret;
	}
	matrix operator^(int to){
		matrix ret,at = *this;
		ret.I();
		while(to){
			if(to&1)ret = ret*at;
			at = at*at;
			to>>=1;
		}
		return ret;
	}  
};
int main(){
	scanf("%d%d%d%d",&x,&k,&n,&q);
	if(n == 1)return puts("0"),0;
	for(int i = 1;i <= k;i++)scanf("%d",c + i);
	for(int i = 0;i < q;i++)scanf("%d %d",p + i,w + i),mp[p[i]] = w[i];
	for(int i = 0;i < (1<<k);i++)
		if(__builtin_popcount(i) == x)
			at[i] = v.size(),
			v.push_back(i);
	matrix main1;
	for(auto i : v)
		if(i&1)
			for(int j = 1;j <= k;j++){
				if(i&(1<<j))continue;
				int nw = (i|(1<<j))>>1;
				main1.mat[at[i]][at[nw]] = c[j];
			}
		else main1.mat[at[i]][at[i>>1]] = 0;
    vector<int>bad;
	for(int i = 0;i < q;i++)
		for(int j = -k;j != 1;j++)
			bad.push_back(max(1,p[i] + j));
	bad.push_back(n - x);
	sort(bad.begin(),bad.end());
	bad.resize(unique(bad.begin(),bad.end()) - bad.begin());
    while(bad.back() > n - x)bad.pop_back();
	matrix ans;
	ans.I();
	int at = 1;
	for(auto i : bad){
	    if(i - at)ans = ans*(main1^(i - at));
		at = i;
		matrix temp = main1;
		for(auto q : v)
			if(q&1)
				for(int j = 1;j <= k;j++){
			    	if((q&(1<<j)) || mp.find(at + j) == mp.end())continue;
			    	int nw = (q|(1<<j))>>1;
			    	temp.mat[::at[q]][::at[nw]]+=mp[at + j];
		    	}
	    ans = ans*temp;
	    at = i + 1;
	}
	printf("%lld\n",ans.mat[0][0]);
}