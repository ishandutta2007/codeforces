#include<cstdio>
#include<cstring>
const int L=2e5+10;
char tmp[L];int l;
struct hp{
	int d[L+10];
	inline void read(){
		scanf("%s",tmp);
		for(int i=0;i<l;i++)d[i]=tmp[l-i-1]-97;
	}
	inline void print(){
		for(int i=l-1;~i;i--)putchar(d[i]+97);
	}
	inline hp operator+(hp b){
		hp c;memset(c.d,0,sizeof c.d);
		for(int i=0;i<L;i++)
		  c.d[i]+=d[i]+b.d[i],c.d[i+1]+=c.d[i]/26,c.d[i]%=26;
		return c;
	}
	inline hp div2(){
		hp c;memset(c.d,0,sizeof c.d);
        for(int i=L-1;~i;i--){
          c.d[i]+=d[i]>>1;
          if(i)d[i-1]+=(d[i]&1)*26;
        }return c;
	}
}s,t;
int main(){
	scanf("%d",&l);
	s.read(),t.read();
	(s+t).div2().print();
	return 0;
}