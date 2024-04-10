    #include<cstdio>
    using namespace std;
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
    const int o=1010;
    int T,n,x,u,v,d[o];
    int main(){
    	read(T);while(T--){
    		read(n);read(x);for(int i=1;i<=n;++i) d[i]=0;
    		for(int i=1;i<n;++i) read(u),read(v),++d[u],++d[v];
    		if(d[x]<=1){printf("Ayush\n");continue;}
    		if(n&1) printf("Ashish\n");
    		else printf("Ayush \n"); 
    	}
    	return 0;
    }