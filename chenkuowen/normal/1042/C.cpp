#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_N=5+2e5;
bool mark[MAX_N];
int a[MAX_N];
vector<int> d;
int main(){
	int n,cnt=0; scanf("%d",&n);
	for(int i=1;i<=n;++i) mark[i]=true;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]<0) ++cnt;
		if(a[i]==0) d.push_back(i),mark[i]=false;
	}
	if(cnt&1){
		int j=0;
		for(int i=1;i<=n;++i)
			if(a[i]<0&&(j==0||a[j]<a[i]))
				j=i;
		if(!d.empty()){
			for(int i=0;i<(int)d.size();++i)
				printf("1 %d %d\n",d[i],j);
		}
		if(n-1!=(int)d.size()) printf("2 %d\n",j),mark[j]=false;
	}else if(!d.empty()){
		for(int i=1;i<(int)d.size();++i)
			printf("1 %d %d\n",d[i-1],d[i]);
		if(n!=(int)d.size()) printf("2 %d\n",d.back());
	}
	d.clear();
	for(int i=1;i<=n;++i)
		if(mark[i]) d.push_back(i);
	for(int i=1;i<(int)d.size();++i)
		printf("1 %d %d\n",d[i-1],d[i]);
	return 0;
}