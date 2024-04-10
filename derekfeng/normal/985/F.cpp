#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
using namespace std;
typedef long long ll;
const ll hast1=257,hast2=233;
const ll MOD1=1e9+7,MOD2=932334239;
int n,m,wantt[26];
string s;
vector<int>t[26];
ll num1[26][200004],num2[26][200004];
ll hash1[200004],hash2[200004];
ll dat1[200004],dat2[200004];
void init(){
	for (int i=1;i<=n;i++)t[s[i]-'a'].push_back(i); 
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++) num1[j][i]=num1[j][i-1]*hast1%MOD1,num2[j][i]=num2[j][i-1]*hast2%MOD2;
		num1[s[i]-'a'][i]++,num2[s[i]-'a'][i]++;
		num1[s[i]-'a'][i]%=MOD1,num2[s[i]-'a'][i]%=MOD2;
		hash1[i]=(hash1[i-1]*hast1+s[i])%MOD1,hash2[i]=(hash2[i-1]*hast2+s[i])%MOD2;
	}
}
int main(){
	cin>>n>>m>>s;
	s="0"+s;
	init();
	dat1[0]=1,dat2[0]=1;
	for (int i=1;i<=n;i++)
		dat1[i]=dat1[i-1]*hast1%MOD1,dat2[i]=dat2[i-1]*hast2%MOD2;
	while (m--){
		int ok=1;
		memset (wantt,-1,sizeof(wantt));
		int x,y,len;
		scanf ("%d%d%d",&x,&y,&len);
		int z=x+len-1,d=y+len-1;
		for (int i=0;i<26 && ok;i++){
			int num1=upper_bound(t[i].begin(),t[i].end(),d)-t[i].begin();
			int num2=lower_bound(t[i].begin(),t[i].end(),y)-t[i].begin();
			if (num1-num2>0){
				int qtl=t[i][num2];
				int spos=qtl-y+x;
				if (wantt[s[spos]-'a']!=-1) ok=0;
				wantt[s[spos]-'a']=i;
			}
		}
		for (int i=0;i<26 && ok;i++){
			int num1=upper_bound(t[i].begin(),t[i].end(),z)-t[i].begin();
			int num2=lower_bound(t[i].begin(),t[i].end(),x)-t[i].begin();
			if (num1-num2>0 && wantt[i]==-1) ok=0;
		} 
		if (!ok){
			puts("NO");continue;
		}
		ll hash01=(hash1[z]-hash1[x-1]*dat1[len]%MOD1+MOD1)%MOD1,hash02=(hash2[z]-hash2[x-1]*dat2[len]%MOD2+MOD2)%MOD2;
		for (int i=0;i<26;i++){
			if (wantt[i]==-1) continue;
			char c1=i+'a';
			ll res1=(num1[i][z]-num1[i][x-1]*dat1[len]%MOD1+MOD1)%MOD1,res2=(num2[i][z]-num2[i][x-1]*dat2[len]%MOD2+MOD2)%MOD2;
			hash01=(hash01-res1*c1%MOD1+MOD1)%MOD1,hash02=(hash02-res2*c1%MOD2+MOD2)%MOD2;
			c1=wantt[i]+'a'; 
			hash01=(hash01+res1*c1)%MOD1,hash02=(hash02+res2*c1)%MOD2;
		}
		ll ans1=(hash1[d]-hash1[y-1]*dat1[len]%MOD1+MOD1)%MOD1,ans2=(hash2[d]-hash2[y-1]*dat2[len]%MOD2+MOD2)%MOD2;
		if (hash01==ans1 && hash02==ans2){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
}