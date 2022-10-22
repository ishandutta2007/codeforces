#include<cstdio>
#include<cstring>
const int L=1e5+9;
struct hp{
	int d[L];
	inline hp operator+(hp b)
	{
		hp c;memset(c.d,0,sizeof c.d);
		for(int i=0;i<L;i++){
		  c.d[i]+=d[i]+b.d[i];
		  if(c.d[i]>9)c.d[i+1]++,c.d[i]-=10;
		}return c;
	}
	inline bool operator>(hp b){
		for(int i=L-1;~i;i--)
		  {if(d[i]>b.d[i])return 1;if(d[i]<b.d[i])return 0;}
		return 0;
	}
	inline bool operator==(hp b){
		for(int i=L-1;~i;i--)
		  if(d[i]!=b.d[i])return 0;
		return 1;
	}
	inline void Print(){
		int f=0;
		for(int i=L-1;~i;i--)
		  (f=d[i]?1:f)?printf("%d",d[i]):0;
		if(!f)putchar(48);
	}
}s1,s2,zero;
int l;char t[100002];
inline hp Stohp(char*t,int l){
	hp c;memset(c.d,0,sizeof c.d);
	for(int i=0;i<l;i++)
	  c.d[i]=t[l-i-1]-48;
	return c;
}
int main(){
	int left,right;
	scanf("%d%s",&l,t);
	if(~l&1){
	  if(t[l>>1]!='0'){(Stohp(t,l>>1)+Stohp(t+(l>>1),l>>1)).Print();return 0;}
	  for(left=l>>1;t[left]=='0'&&left;left--);
	  if(left)s1=Stohp(t,left)+Stohp(t+left,l-left);
	  for(right=l>>1;right<l&&t[right]=='0';right++);
	  if(right<l)s2=Stohp(t,right)+Stohp(t+right,l-right);
	  if((s2>s1||s2==zero)&&!(s1==zero))s1.Print();
	  if((s1>s2||s1==zero)&&!(s2==zero))s2.Print();
	  return 0; 
	}
	for(left=l>>1;t[left]=='0'&&left;left--);
	if(left)s1=Stohp(t,left)+Stohp(t+left,l-left);
	for(right=(l>>1)+1;right<l&&t[right]=='0';right++);
	if(right<l)s2=Stohp(t,right)+Stohp(t+right,l-right);
	if((s2>s1||s2==zero)&&!(s1==zero))s1.Print();
	if((s1>s2||s1==zero)&&!(s2==zero))s2.Print();
	return 0;
}