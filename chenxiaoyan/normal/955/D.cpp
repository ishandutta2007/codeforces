/*








*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=500000,M=500000;
int n,m,s,t;
int rev_pos(int pos){return n+1-pos;}
char a[N+5],b[M+5],ra[N+5],rb[M+5],c[N+1+M+5];
void con(char str1[],char str2[]){
	t=0;
	for(int i=1;i<=m;i++)c[++t]=str1[i];
	c[++t]='!';
	for(int i=1;i<=n;i++)c[++t]=str2[i];
}
int z1[N+1+M+1],z2[N+1+M+1];
void z_init(int z[]){
	int zl=0,zr=0;
	for(int i=2;i<=t;i++)
		if(zr<i){
			while(i+z[i]<=t&&c[i+z[i]]==c[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]<=zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=t&&c[i+z[i]]==c[1+z[i]])z[i]++;
			zl=i;zr=i+z[i]-1;
		}
}
int lft[M+1],rit[M+1];
vector<int> dadd[M+1],ddel[N+1];
multiset<int> st;
int main(){
	cin>>n>>m>>s>>a+1>>b+1;
	memcpy(ra+1,a+1,n+1);reverse(ra+1,ra+n+1);
	memcpy(rb+1,b+1,m+1);reverse(rb+1,rb+m+1);
	con(b,a);z_init(z1);
	con(rb,ra);z_init(z2);
	if(s>=m)
		for(int i=1;i<=n;i++)
			if(z1[m+1+i]==m){
				int l=max(1,i-(s-m)),r=l+s;
				if(r+s-1<=n)return cout<<"Yes\n"<<l<<" "<<r,0;
				r=min(n,i+s-1)-s+1;l=r-s;
				if(l>=1)return cout<<"Yes\n"<<l<<" "<<r,0;
			}
	for(int i=1;i<=n;i++){
		int l=max(s-(i-1),1),r=z1[m+1+i];
		if(l>r)continue;
		dadd[l].pb(i-s);if(r<m)ddel[r+1].pb(i-s);
	}
	st.insert(inf);
	for(int i=1;i<=m;i++){
		for(int j=0;j<dadd[i].size();j++)st.insert(dadd[i][j]);
		for(int j=0;j<ddel[i].size();j++)st.erase(ddel[i][j]);
		lft[i]=*st.begin()+i;
	}
	for(int i=1;i<=m;i++)dadd[i].clear(),ddel[i].clear();
	for(int i=1;i<=n;i++){
		int l=max(s-(n-i),1),r=z2[m+1+rev_pos(i)];
		if(l>r)continue;
		dadd[l].pb(i+1);if(r<m)ddel[r+1].pb(i+1);
	}
	st.clear();st.insert(-inf);
	for(int i=1;i<=m;i++){
		for(int j=0;j<dadd[i].size();j++)st.insert(dadd[i][j]);
		for(int j=0;j<ddel[i].size();j++)st.erase(ddel[i][j]);
		rit[i]=*--st.end()-i;
	}
//	for(int i=1;i<=m;i++)printf("lft[%d]=%d rit[%d]=%d\n",i,lft[i],i,rit[i]);
	for(int i=0;i<=s;i++)if(0<=m-i&&m-i<=s)
		if(lft[i]+s-1<rit[m-i])
			return cout<<"Yes\n"<<lft[i]<<" "<<rit[m-i],0;
	puts("No");
	return 0;
}
/*1
7 4 3
baabaab
aaaa
*/
/*2
6 3 2
cbcbcb
bcc
*/
/*3
7 5 3
aabbaaa
aaaaa
*/
/*4
12 3 4
dbcbabbbdcbb
bba
*/
/*5
7 3 3
aaabbaa
aaa
*/