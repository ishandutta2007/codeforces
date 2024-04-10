#include<cstdio>
#include<cstring>
char s[204800],v[]="AEIOUaeiou";
int l,c,n,x[204800],y[204800],L,R,M,i;
int main(){
	gets(s);
	for(;s[l];++l)if(!strchr(v,s[l])){
		x[n]=l;y[n]=l-n*3;
		for(L=-1,R=n;L+1<R;)
			y[M=(L+R)/2]+2>=y[n]?R=M:L=M;
		if(n-R>=i)i=n-R+1;
		if(n&&y[n-1]>y[n])y[n]=y[n-1];
		++n;
	}
	L=(M=i)--*3;if(l<L)L=l;
	for(i=R=0;i+L<=l;++i){
		if(x[R]<i)R++;
		if(R+M==n)break;
		if(x[R]>=i+L)continue;
		if(x[R+M]<i+L)++c;
	}
	L?printf("%d %d\n",L,c):puts("No solution"); 
	return 0;
}