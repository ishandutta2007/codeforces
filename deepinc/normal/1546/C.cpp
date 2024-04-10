#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int $=555555;
int n,a[$],b[$][2];
int main(){
	int t;cin>>t;while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]][i&1]++;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)b[a[i]][i&1]--;
		for(int i=1;i<=n;++i)if(b[a[i]][0]||b[a[i]][1]){puts("NO");goto F;}
		puts("YES");F:
		for(int i=1;i<=n;++i)b[a[i]][0]=b[a[i]][1]=0;
	}
}