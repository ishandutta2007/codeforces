#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<time.h>
#include<set>
#define cl_has_dh(x...) cl_get_th_100(\
x,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,\
0)
#define cl_get_th_100(\
 _0, _1, _2, _3, _4, _5, _6, _7, _8, _9,\
_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,\
_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,\
_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,\
_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,\
_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,\
_60,_61,_62,_63,_64,_65,_66,_67,_68,_69,\
_70,_71,_72,_73,_74,_75,_76,_77,_78,_79,\
_80,_81,_82,_83,_84,_85,_86,_87,_88,_89,\
_90,_91,_92,_93,_94,_95,_96,_97,_98,_99,\
_100,x...) _100
#if 0
#define cl_blzk cl_blzk0
#else
#define cl_blzk cl_blzk3
#endif
#define cl_blzk0(x...) cl_blzk1(cl_blzk1(cl_blzk1(x)))
#define cl_blzk1(x...) cl_blzk2(cl_blzk2(cl_blzk2(x)))
#define cl_blzk2(x...) cl_blzk3(cl_blzk3(cl_blzk3(x)))
#define cl_blzk3(x...) cl_blzk4(cl_blzk4(cl_blzk4(x)))
#define cl_blzk4(x...) cl_blzk5(cl_blzk5(cl_blzk5(x)))
#define cl_blzk5(x...) cl_blzk6(cl_blzk6(cl_blzk6(x))) 
#define cl_blzk6(x...) cl_blzk7(cl_blzk7(cl_blzk7(x))) 
#define cl_blzk7(x...) x
#define cl_lj_(a,b) a##b
#define cl_lj(a,b) cl_lj_(a,b)
#define cl_not(x) cl_lj(cl_not_,x)
#define cl_not_0 1
#define cl_not_1 0
#define cl_and(x,y) cl_lj(cl_and_,cl_lj(x,y))
#define cl_and_00 0
#define cl_and_01 0
#define cl_and_10 0
#define cl_and_11 1
#define cl_bif(x) cl_lj(cl_bif_,x)
#define cl_bif_0(x...) cl_bif_0_
#define cl_bif_0_(x...) x
#define cl_bif_1(x...) x cl_bif_1_
#define cl_bif_1_(x...)
#define cl_nn(x...)
#define cl_zzk(x...) x
#define cl_zkk(x...) x
#define cl_after(x...) cl_zzk cl_nn() (x)
#define cl_txt(x...) #x
#define cl_show(x...) puts(cl_txt(x))
#define cl_is_nn(x...) cl_is_nnmm(x)
#define cl_x_to_dh(x...) ,
#define cl_is_nnmm(x...) cl_and(cl_and(cl_not(cl_has_dh(cl_x_to_dh x)),cl_has_dh(cl_x_to_dh x ())),cl_not(cl_has_dh(x ())))
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull; 
#define gs1(x,y,z) (quick_IO::very_important_cs_scw=y,quick_IO::very_important_cs_xsd=z,x)
#define gs0(x,y) (quick_IO::very_important_cs_scw=y,x)
#define gs(x,y...) cl_lj(gs,cl_has_dh(y))(x,y)
#define read_cz(cs,_1,_01) cl_bif(_01)((+)quick_IO::whreadm(_1)cl_zkk)(()cl_nn)
#define write_cz(cs,_1,_01) cl_bif(_01)((,)quick_IO::whwritem(_1)cl_zkk)(()cl_nn)
#define read(x...) (cl_blzk(cl_nn cl_d(read_cz,,x) ()))
#define write(x...) cl_blzk(cl_nn cl_d(write_cz,,x) ())
#define cl_pp(cs,x...) cl_blzk(cl_d(cl_pp_cz,cs,x))
#define cl_pp_cz(cs,_1,_01) cl_bif(_01)(template<>struct cs<_1>{typedef _1 Type;};)()
#define cl_d(cz,cs,x...) cl_ds(cz,cs,x)
#define cl_ds(cz,cs,x...) cl_lj(cl_ds_,cl_is_nn(x))(cz,cs,x)
#define cl_ds_1(cz,cs,_1,x...) cz(cs,_1,0)
#define cl_ds_0(cz,cs,_1,x...) cz(cs,_1,1) cl_after(cl_ds_cpy)()(cz,cs,x)
#define cl_ds_cpy() cl_ds
#define isdigit(x) (x >= '0' && x <= '9')
#define pp(a,b) template<>struct a<b>{typedef b Type;};
namespace quick_IO {
	inline bool blank(char ch) {return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
  	ll very_important_cs_scw=0,very_important_cs_xsd=6,cs=0;
  	inline char gc() {return getchar();}
  	inline void pc(char c) {cs?fprintf(stderr,"%c",c):putchar(c);}
	template <typename T> struct Checker1;
	cl_pp(Checker1,bool,int,short,long,long long,unsigned int,unsigned long,unsigned short,unsigned long long,double,long double,float)
	template <typename T> struct Checker2;
	cl_pp(Checker2,char)
	char lastc=-2;
	template <typename T>inline ll readm(typename Checker1<T>::Type&x) {
	    register double tmp=1;register bool sign=0; x=0;register char ch=lastc==-2?gc():lastc;
	    for (;!isdigit(ch);ch=gc()) if(ch=='-') sign=1;else if(ch==EOF) return 0;for (;isdigit(ch);ch=gc()) x=x*10+(ch-'0');
	    if (ch=='.') for (ch=gc();isdigit(ch);ch=gc()) tmp/=10.0,x+=tmp*(ch-'0');if (sign) x=-x;lastc=ch;return 1;
	}
	template <typename T>inline ll readm(typename Checker2<T>::Type&c) {
		for(c=lastc==-2?gc():lastc;blank(c);c=gc());if(c==EOF)return 0;
		lastc=-2;return 1;
	}
  	inline ll readm(char *s)
	{
    	register char ch=lastc==-2?gc():lastc;for (;blank(ch)&&~ch;ch=gc())if(ch==EOF)return 0;
		for (;~ch&&!blank(ch);ch=gc()) *s++=ch;*s=0;lastc=-2;return 1;
  	}
	void writellm(ll c,ll x) {
		if(c<0)pc('-'),c=-c,x--;
		if(c<10)return ({for(ll i=1;i<=x-1;i++)pc(' ');pc(c^48);void(0);});
		writellm(c/10,x-1);pc((c%10)^48);
	}
	void writeullm(ull c,ll x) {
		if(c<10)return ({for(ll i=1;i<=x-1;i++)pc(' ');pc(c^48);void(0);});
		writeullm(c/10,x-1);pc((c%10)^48);
	}
	template<typename T>ll whreadm(T*x){return readm(x);};
	template<typename T>ll whreadm(T&x){return readm<T>(x);};
		#define x very_important_cs_xsd
		#define y very_important_cs_scw
	template<typename T>void writem(typename Checker2<T>::Type c) {
		for(ll i=1;i<=y-1;i++)pc(' ');pc(c);
	}
	template <typename T> struct Checkers1;
	template <typename T> struct Checkers2;
	cl_pp(Checkers1,bool,int,short,long,long long)
	cl_pp(Checkers2,unsigned int,unsigned long,unsigned long long)
	template <typename T>inline void ycl(typename Checkers1<T>::Type&c){if(c<0)pc('-'),c=-c;x=0;}
	template <typename T>inline void ycl(typename Checkers2<T>::Type&c){x=0;}
	template <typename T>void ycl(T&c){if(c<0)putchar('-'),c=-c;long double ys=0.5;for(ll i=1;i<=x;i++)ys/=10;c+=ys;}
	template <typename T>void ycl2(T&c){writeullm(ull(c),y-(x?x+1:0));}
	template <typename T>void ycl2(typename Checkers2<T>::Type c){writeullm(ull(c),y-(x?x+1:0));}
	template<typename T>void writem(typename Checker1<T>::Type c) {
		ycl<T>(c);
		ycl2<T>(c);
		c-=ll(c);if(!x)return;
		pc('.');for(ll i=1;i<=x;i++)c*=10,pc(int(c)^48),c-=char(c);
	}
	void writem(const char* c) {
		ll len=std::strlen(c);for(ll i=1;i<=y-len;i++)pc(' ');
		while(*c)pc(*c++); 
	}
	#undef x
	#undef y
	template<typename T>void whwritem(T*x){writem(x);very_important_cs_scw=0,very_important_cs_xsd=6;};
	template<typename T>void whwritem(T x){writem<T>(x);very_important_cs_scw=0,very_important_cs_xsd=6;};
	template<typename T>inline const T&max(const T&a,const T&b){return a>b?a:b;}
	template<typename T>inline T&max(T&a,T&b){return a>b?a:b;}
	template<typename T>inline const T&min(const T&a,const T&b){return a<b?a:b;}
	template<typename T>inline T&min(T&a,T&b){return a<b?a:b;}
}
#define IO_debug 0
#define IO(x) freopen(#x".in","r",stdin)cl_bif(IO_debug)()(;freopen(#x".out","w",stdout))
#define bla ,(((zjhyyds))),
#define cl_del_3_kh(x...) cl_bif(cl_has_3_kh(x))(cl_del_2_kh x)(x)
#define cl_del_2_kh(x...) cl_bif(cl_has_2_kh(x))(cl_del_1_kh x)(x)
#define cl_del_1_kh(x...) cl_bif(cl_has_1_kh(x))(cl_zkk x)(x)
#define cl_has_3_kh(x...) cl_bif(cl_has_1_kh(x))(cl_has_2_kh x)(0)
#define cl_has_2_kh(x...) cl_bif(cl_has_1_kh(x))(cl_has_1_kh x)(0)
#define cl_has_1_kh(x...) cl_is_nn(cl_nn x)
#define is_zjhyyds(x) cl_bif(cl_has_3_kh(x))(cl_is_nn(is_zjhyyds_(x)))(0)
#define is_zjhyyds_(x) cl_lj(is_zjhyyds_s,cl_del_3_kh(x))
#define is_zjhyyds_szjhyyds
#define cl_rir_dh(cs,x...) cl_zzk(cl_nn cl_rir(cs,(,)x cl_zzk)())
#define cl_rir(cs,x...) cl_blzk(cl_d(cl_rir_cz,(x),cl_zkk cs))
#define cl_rir_cz(cs,_1,_01) cl_bif(_01)(cl_after(cl_hg_cpy)()(_1,cl_zkk cs))()
#define cl_hg_cpy() cl_hg
#define cl_hg(cs,x...) cl_nn cl_after(cl_ds_cpy)()(cl_hg_cz,cs,x)()
#define cl_hg_cz(cs,_1,_01) cl_bif(_01)(cl_bif(is_zjhyyds(_1))(()cs cl_nn)((,)_1 cl_zkk))(()cl_nn)
ll readll(void){ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';(c-'-')||(w=-w),c=getchar());for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());return x*w;}
#define cl_rill(x...) cl_blzk(cl_nn cl_d(cl_rill_cz,,x)())
#define rill(x...) cl_rill(x)
#define cl_rill_cz(cs,_1,_01) cl_bif(_01)((,)_1=readll()cl_zkk)(()cl_nn)
#define writeln(x...) (cl_bif(cl_is_nn(x))(write('\n'))(write(x,'\n')))
#define rep(cs,low,up,x...) rfor(ll cs=low;cs<=up;cl_bif(cl_is_nn(x))(++cs)(x))
#define per(cs,low,up,x...) rfor(ll cs=low;cs>=up;cl_bif(cl_is_nn(x))(--cs)(x))
#define cl_hsdd(hs,x...) cl_blzk(cl_bif(cl_is_nn(x))()(cl_hsdd_(hs,x)))
#define cl_hsdd_(hs,_1,x...) cl_lj(cl_hsdd_,cl_is_nn(x))(hs,_1,x)
#define cl_hsdd_1(hs,_1,x...) _1
#define cl_hsdd_0(hs,_1,x...) hs(_1,cl_after(cl_hsdd_cpy)()(hs,x))
#define cl_hsdd_cpy() cl_hsdd_
#define max(x...) cl_hsdd(quick_IO::max,x)
#define min(x...) cl_hsdd(quick_IO::min,x)
#define rfor(x...) for(register x)
#define ssscc 1
#if 1
#define debug(x...) quick_IO::cs=ssscc,write(x),quick_IO::cs=0
#define debugln(x...) quick_IO::cs=ssscc,writeln(x),quick_IO::cs=0
#else
#define debug(x...) quick_IO::cs=0
#define debugln(x...) quick_IO::cs=0
#endif
#define sys(f,x...) #f cl_rir((x),,'[',bla,']'),'=',f cl_rir((x),[bla])
#define WA do{puts("YOU DIED!");exit(0);}while(0)
#define TLE do{}while(1)
#define MLE do{new int;}while(1)
#define RE do{ll*__s=new ll[1];__s[-314514]=0;}while(0)
ll f[14][1<<14],nt[1<<14];
struct x2{
	ll x,y;
}e[1333];
struct x3{
	ll x,y,z;
}lca[1333];
template<typename T>
int cmp(T x,T y){
	return x.x<y.x;
}
//char s1[114514],s2[114514],s3[114514];
const ll mod=1e9+7,k=114599;
ll km[114514];
struct calc{
	calc(){
		km[0]=1;
		rep(i,1,114500)km[i]=km[i-1]*k%mod;
	}
};
const calc calcer;
inline add(ll x,ll y){
	ll c=x+y;
	return c>=mod?c-mod:c;
}
struct hash{
	ll kc[2555];
	hash(const char*f){
		ll lenf=strlen(f+1);
		kc[0]=0;
		rep(i,1,lenf)kc[i]=(kc[i-1]*k+f[i]-96)%mod;
	}
	ll operator()(ll l,ll r)const{
		if(l>r)return 0;
		return add(mod-kc[l-1]*km[r-l+1]%mod,kc[r]);
	}
};
ll len1,len2;
typedef char str[114514];
str s1,s2,s3,s4;
//
struct mint{
	ll x;
	operator ll()const{
		return x;
	}
	mint(ll y=0):x(y){x>=mod&&(x%=mod);}
	mint operator+(const mint&b)const{
		ll c=x+b.x;
		return c>=mod?c-mod:c;
	}
	mint&operator+=(const mint&b){x+=b.x,x>=mod&&(x-=mod);return*this;}
	mint operator++(int){ll lx=x;++x>=mod&&(x=0);return mint(lx);}
	mint operator--(int){ll lx=x;--x<0&&(x=mod-1);return mint(lx);}
	mint&operator++(){++x>=mod&&(x=0);return*this;}
}ans;
typedef mint ar[2555][2555];
ar f1,f2,f12,f21;
void work(){
	hash h1(s1),h2(s2),h3(s3),h4(s4);
	memset(f1,0,sizeof f1);
	memset(f2,0,sizeof f2);
	memset(f12,0,sizeof f12);
	memset(f21,0,sizeof f21);
	rep(i,0,len1){
		rep(j,0,min(len2/2,(ll)i))
		if(j!=1){
			if(h2(i-j+1,i)==h4(len2-j+1,len2)&&h1(i-j+1,i)==h3(j+1,2*j)){
				f21[i][j*2]++;
//				writeln(0,sys(f21,i,j*2));
			}
			if(h1(i-j+1,i)==h4(len2-j+1,len2)&&h2(i-j+1,i)==h3(j+1,2*j)){
				f12[i][j*2]++;
//				writeln(1,sys(f12,i,j*2));
			}
		}
		rep(j,1,len2){
			if(s1[i]==s3[j])f1[i][j]+=f1[i-1][j-1]+f21[i-1][j-1],f21[i][j]+=f2[i][j-1];
			if(s2[i]==s3[j])f2[i][j]+=f2[i-1][j-1]+f12[i-1][j-1],f12[i][j]+=f1[i][j-1];
//			writeln(2,sys(f1,i,j));
//			writeln(2,sys(f21,i,j));
//			writeln(2,sys(f12,i,j));
//			writeln(2,sys(f2,i,j));
		}
	}
	rep(i,0,len1)
	rep(j,0,min(len2/2-1,len1-i))
	if(j!=1){
		if(h2(i+1,i+j)==h4(1,j)&&h1(i+1,i+j)==h3(len2-2*j+1,len2-j)){
			ans+=f21[i][len2-j*2]+f1[i][len2-j*2];
//			writeln(ans,' ',i,' ',len2-j*2);
		}
		if(h1(i+1,i+j)==h4(1,j)&&h2(i+1,i+j)==h3(len2-2*j+1,len2-j)){
			ans+=f12[i][len2-j*2]+f2[i][len2-j*2];
//			writeln(ans,' ',i,' ',len2-j*2);
		}
	}
}
int main(){
	//IO(t2);
	read(s1+1,s2+1,s3+1);
	len1=strlen(s1+1),len2=strlen(s3+1);
	rep(i,1,len2)s4[i]=s3[len2-i+1];
	work();
	rep(i,1,len1)if(i<len1-i+1)std::swap(s1[i],s1[len1-i+1]),std::swap(s2[i],s2[len1-i+1]);
	work();
//	ans>>=!~-len2;
	if(len2==2)rep(i,1,len1){
		if(s3[1]==s1[i]&&s3[2]==s2[i])ans--;
		if(s3[1]==s2[i]&&s3[2]==s1[i])ans--;
	}
	if(len2==1)rep(i,1,len1){
		if(s3[1]==s1[i])ans++;
		if(s3[1]==s2[i])ans++;
	}
	writeln((ll)ans);
	return 0;
}
//