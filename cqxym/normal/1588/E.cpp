#include<iostream>
#include<math.h>
using namespace std;
#define R register int
#define L long long
#define D double
#define I inline
#define PIE 3.141592653589793
int px[3000],py[3000];
struct Segment{
	D Lf,Rt;
	I friend Segment operator|(Segment A,Segment B){
		if(A.Lf>A.Rt-1e-8){
			return B;
		}
		if(B.Lf>B.Rt-1e-8){
			return A;
		}
		if(A.Rt>=PIE&&B.Lf<=-PIE){
			A.Rt=B.Rt;
			return A; 
		}
		if(B.Rt>=PIE&&A.Lf<=-PIE){
			A.Lf=B.Lf;
			return A;
		}
		if(B.Lf<A.Lf){
			A.Lf=B.Lf;
		}
		if(B.Rt>A.Rt){
			A.Rt=B.Rt;
		}
		return A;
	}
	I friend Segment operator&(Segment A,Segment B){
		if(A.Lf>A.Rt+1e-8){
			Segment C1,C2;
			C1.Lf=A.Lf;
			C1.Rt=PIE;
			C2.Lf=-PIE;
			C2.Rt=A.Rt;
			return C1&B|C2&B;
		}
		if(B.Lf>B.Rt+1e-8){
			Segment C1,C2;
			C1.Lf=B.Lf;
			C1.Rt=PIE;
			C2.Lf=-PIE;
			C2.Rt=B.Rt;
			return C1&A|C2&A;
		}
		if(A.Rt<B.Lf||A.Lf>B.Rt){
			A.Lf=PIE+1e-8;
			A.Rt=PIE;
			return A;
		}
		if(A.Lf<B.Lf){
			A.Lf=B.Lf;
		}
		if(A.Rt>B.Rt){
			A.Rt=B.Rt;
		}
		return A;
	}
}s[3000];
I bool CheckIn(Segment S,D x){
	if(S.Lf>PIE){
		return false;
	}
	if(S.Lf<S.Rt){
		return S.Lf<=x&&x<=S.Rt;
	}
	return x>=S.Lf||x<=S.Rt;
} 
I bool Check(int x,int y){
	D a=atan2(py[y]-py[x],px[y]-px[x]);
	if(CheckIn(s[x],a)==false){
		return false;
	}
	a+=PIE;
	if(a>PIE){
		a-=PIE*2;
	}
	return CheckIn(s[y],a);
}
int main(){
	int n,r,ans=0;
	cin>>n>>r;
	for(R i=0;i!=n;i++){
		cin>>px[i]>>py[i];
	}
	for(R i=0;i!=n;i++){
		s[i].Lf=-PIE;
		s[i].Rt=PIE;
		for(R j=0;j!=n;j++){
			if(i!=j){
				L dis=(L)(px[i]-px[j])*(px[i]-px[j])+(L)(py[i]-py[j])*(py[i]-py[j]);
				if(dis>(L)r*r){
					D d=asin(r/sqrt(dis)),a=atan2(py[j]-py[i],px[j]-px[i]);
					Segment S;
					S.Lf=a-d;
					S.Rt=a+d;
					if(S.Lf<-PIE){
						S.Lf+=PIE*2;
					}else if(S.Rt>PIE){
						S.Rt-=PIE*2;
					}
					s[i]=s[i]&S;
				}
			}
		}
	}
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			if(Check(i,j)==true&&Check(j,i)==true){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}