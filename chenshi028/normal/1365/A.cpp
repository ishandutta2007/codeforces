#include<cstdio>
#include<cstring>
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
int T,n,m,l,c;bool a[60][60],cl[60],ln[60];
int main(){
	read(T);while(T--){
		read(n);read(m);memset(cl,0,sizeof cl);memset(ln,l=c=0,sizeof ln);
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) read(a[i][j]),ln[i]|=a[i][j],cl[j]|=a[i][j];
		for(int i=1;i<=n;++i) l+=ln[i];l=n-l;
		for(int j=1;j<=m;++j) c+=cl[j];c=m-c;
		if(l>c) l=c;printf(l&1?"Ashish\n":"Vivek\n");
	}
	return 0;
}