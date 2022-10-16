#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int t,n,l[3005],r[3005],s[6005],tot,f[6005][6005];
bool book[6005][6005];
vector <int>c[6005];
inline int lower(int x){
	for (register int i=1;i<=tot;i++)
		if (s[i]==x)return i;
	return 0;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)c[i].clear();
		for (register int i=0;i<=2*n;i++)	
			for (register int j=0;j<=2*n;j++)	
				 f[i][j]=0,book[i][j]=0;
		tot=0;
		for (int i=1;i<=n;i++){
			cin>>l[i]>>r[i];
			s[++tot]=l[i];
			s[++tot]=r[i];
		}
		sort(s+1,s+1+tot);
		for (int i=1;i<=n;i++){
			l[i]=lower(l[i]),r[i]=lower(r[i]);
			book[l[i]][r[i]]=1;
			c[l[i]].push_back(r[i]);
		}
		for (register int i=1;i<=2*n;i++){
			if (book[i][i]==1)f[i][i]=1;
			for (register int j=i-1;j>=1;j--){
				f[j][i]=max(f[j+1][i],f[j][i-1])+book[j][i];
				for (register int k=0,len=c[j].size();k<len;k++)
					if (c[j][k]<i)f[j][i]=max(f[j][i],f[j][c[j][k]]+f[c[j][k]+1][i]+book[j][i]);
			}
		}
		cout<<f[1][2*n]<<endl;
	}
}