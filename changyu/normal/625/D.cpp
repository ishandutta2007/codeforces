#include<cstdio>
#include<algorithm>
#include<cstring>
const int N=1e5+3;
int l,s[N],t[N];char c[N];
inline bool Solve1(){
	int m=l>>1;
	for(int i=0;i<l;i++)s[i]=t[i];
	if(s[m]&1){
	  if(m+1<l)s[m]--,s[m+1]+=10;
	  else return 0;
	}
	for(int k=l-1;k>m;k--){
	  if(s[k]==s[m+m-k])continue;
	  if(s[k]==s[m+m-k]-1){
		s[m+m-k]--,s[m+m-k+1]+=10;
		continue;
	  }
	  if(s[k]==s[m+m-k]-10&&k-1>m){
		s[k-1]--,s[k]+=10;
		continue;
	  }
	  if(s[k]==s[m+m-k]-11&&k-1>m){
		s[m+m-k]--,s[m+m-k+1]+=10;
		s[k-1]--,s[k]+=10;
		continue;
	  }
	  return 0;
	}
	if(!s[0])return 0;
	for(int i=0;i<l;i++)if(s[i]>18||s[i]<0)return 0;
	for(int i=0;i<l;i++){
	  if(i<m)printf("%d",std::min(9,s[i]));
	  if(i==m)printf("%d",s[i]>>1);
	  if(i>m)printf("%d",s[i]-std::min(9,s[i]));
	}puts("");
	return 1;
}
inline bool Solve0(){
	int m=l>>1;
	for(int i=0;i<l;i++)s[i]=t[i];
	for(int k=l-1;k>m;k--){
	  if(s[k]==s[m+m-1-k])continue;
	  if(s[k]==s[m+m-1-k]-1&&m+m-k<m){
		s[m+m-1-k]--,s[m+m-k]+=10;
		continue;
	  }
	  if(s[k]==s[m+m-1-k]-10&&k-1>=m){
		s[k-1]--,s[k]+=10;
		continue;
	  }
	  if(s[k]==s[m+m-1-k]-11&&k-1>=m){
		s[m+m-1-k]--,s[m+m-k]+=10;
		s[k-1]--,s[k]+=10;
		continue;
	  }
	  return 0;
	}
	if(s[m]==s[m-1]-11){
	  s[m-1]--,s[m]+=10;
	}
	if(s[m]!=s[m-1]||!s[0])return 0;
	for(int i=0;i<l;i++)if(s[i]>18||s[i]<0)return 0;
	for(int i=0;i<l;i++){
	  if(i<m)printf("%d",std::min(9,(int)s[i]));
	  if(i>=m)printf("%d",s[i]-std::min(9,(int)s[i]));
	}puts("");
	return 1;
}
int main(){
	scanf("%s",c);
	l=strlen(c);
	for(int i=0;i<l;i++)t[i]=c[i]-'0';
	if(l==1&&t[0]==1)return 0*puts("0");
	if((l&1)&&Solve1())return 0;
	if((~l&1)&&Solve0())return 0;
	if(t[0]==1){
	  t[0]=10+t[1];
	  for(int i=1;i+1<l;i++)t[i]=t[i+1];
	  --l;
	  if((l&1)&&Solve1())return 0;
	  if((~l&1)&&Solve0())return 0;
	}
	puts("0");
	return 0;
}