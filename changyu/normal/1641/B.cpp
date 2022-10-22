#include<bits/stdc++.h>
typedef std::pair<int,int> pii;
const int N=503;
int n,a[N],fr;
std::map<int,int>b;
std::vector<pii>ans0;
std::vector<int>ans1;
inline void Reverse(int l,int r){
	for(int i=l;i<=r;i++)ans0.push_back(pii(fr+r+i-l,a[i]));
	for(int i=l;i<=r;i++)if(2*i<l+r)std::swap(a[i],a[l+r-i]);
	fr+=2*(r-l+1);
	ans1.push_back(2*(r-l+1));
}
signed main(){
	int T;scanf("%d",&T);for(;T--;){
		scanf("%d",&n);
		b.clear(),ans0.clear(),ans1.clear(),fr=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i),++b[a[i]];
		for(int i=1;i<=n;i++)if(b[a[i]]&1){puts("-1");goto Brk;}
		for(int i=1;i<=n;i+=2){
			for(int j=i+1;;j++)
				if(a[i]==a[j]){
					Reverse(i,j-1);
					Reverse(i,j);
					ans1.push_back(2);
					break;
				}
		}
		printf("%d\n",ans0.size());
		for(auto x:ans0)printf("%d %d\n",x.first,x.second);
		printf("%d\n",ans1.size());
		for(auto x:ans1)printf("%d ",x);puts("");
		Brk:;
	}
	return 0;
}