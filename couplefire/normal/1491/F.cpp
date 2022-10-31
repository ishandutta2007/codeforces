#include<bits/stdc++.h>
using namespace std;
#define N 2002
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,T;
int Ask(const vector<int> &A,const vector<int> &B){
	printf("? %d %d\n",(int)A.size(),(int)B.size());
	for(auto x:A)printf("%d ",x);
	printf("\n");
	for(auto x:B)printf("%d ",x);
	printf("\n");
	fflush(stdout);
	return read();
}
vector<int> A,ans;
int main(){
	T=read();
	while(T--){
		A.clear(),ans.clear();
		n=read();
		A.push_back(1);
		int p=0;
		for(p=2;;++p){
			int o=Ask(A,vector<int>(1,p));
			if(o)break;
			A.push_back(p);
		}
		for(int i=p+1;i<=n;++i){
			if(!Ask(vector<int>(1,p),vector<int>(1,i)))ans.push_back(i);
		}
		int l=1,r=p,v=0;
		while(l<r){
			int mid=(l+r)>>1;
			A.clear();
			for(int i=l;i<=mid;++i){
				A.push_back(i);
			}
			if(Ask(A,vector<int>(1,p))){
				v=r=mid;
			}
			else l=mid+1;
		}
		for(int i=1;i<p;++i){
			if(i==v)continue;
			ans.push_back(i);
		}
		printf("! %d",(int)ans.size());
		for(auto x:ans){
			printf(" %d",x);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}