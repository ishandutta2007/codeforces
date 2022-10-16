#include <iostream>
#include <cstdio>
using namespace std;
int n,m,cnt[20][20],bc[1100005],f[1100005];
char s[100005];
inline int lowbit(int x){
	return x&(-x);
}
int main(){
	cin>>n>>m;
	scanf("%s",s+1);
	for (int i=1;i<n;i++)cnt[s[i]-'a'][s[i+1]-'a']++,cnt[s[i+1]-'a'][s[i]-'a']++;
	for (int i=1;i<(1<<m);i++)bc[i]=bc[i-lowbit(i)]+1;
	for (int i=1;i<(1<<m);i++){
		f[i]=1e9;
		for (int j=0;j<m;j++){
			if ((i&(1<<j))==0)continue;
			int s=0;
			for (int k=0;k<m;k++){
				if (k==j)continue;
				if ((i&(1<<k))!=0)s+=bc[i]*cnt[j][k];
				else s-=bc[i]*cnt[j][k];
			}
			f[i]=min(f[i],f[i^(1<<j)]+s);
		}
	}
	cout<<f[(1<<m)-1]<<endl;
	return 0;
}

// cnt[i][j]*i-cnt[i][j]*j