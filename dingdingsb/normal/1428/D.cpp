#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
int n,a[100000+10];
int ans[100000+10][2];
int low=0;//
set<int>can1;//
set<int>can2;// 
int lst[100000+10];
signed main(){
	//freopen("1.in","r",stdin);
	in::read(n);
	for(int i=1;i<=n;i++)
		in::read(a[i]);
	for(int i=n;i>=1;i--)
		if(a[i]==1){
			++low;
			ans[i][0]=low;
			can1.insert(low);
			lst[low]=i;
			can2.insert(i);
		}
		else if(a[i]==2){
			if(!can1.size())
				puts("-1"),exit(0);
			ans[i][0]=*can1.begin();
			can2.erase(lst[*can1.begin()]);
			can1.erase(can1.begin());
			can2.insert(i);
		} 
		else if(a[i]==3){
			if(!can2.size())
				puts("-1"),exit(0);
			low++; 
			ans[i][0]=low;
			ans[*can2.begin()][1]=low;
			can1.erase(ans[*can2.begin()][0]);
			can2.erase(can2.begin());
			can2.insert(i);
		}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ans[i][0])cnt++;
		if(ans[i][1])cnt++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++){
		if(ans[i][0])printf("%d %d\n",n-ans[i][0]+1,i);
		if(ans[i][1])printf("%d %d\n",n-ans[i][1]+1,i);
	}
	out::flush();
	return 0;
}