#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
int n,cnt[2][2];long long s,ans;
int main(){
	read(n);
	for(int i,j;n--;) read(i),read(j),++cnt[(i>>1)&1][(j>>1)&1];
	for(int i1=0;i1<2;++i1) for(int j1=0;j1<2;++j1) if(cnt[i1][j1]){
		s=cnt[i1][j1]--;
		for(int i2=0;i2<2;++i2) for(int j2=0;j2<2;++j2) if(cnt[i2][j2]){
			s*=cnt[i2][j2]--;
			for(int i3=0;i3<2;++i3) for(int j3=0;j3<2;++j3)
				if(((i1-i2||j1-j2)+(i1-i3||j1-j3)+(i2-i3||j2-j3))%2==0) ans+=s*cnt[i3][j3];
			s/=++cnt[i2][j2]; 
		}
		++cnt[i1][j1];
	}
	printf("%lld",ans/6);
	return 0;
}