#include<iostream>
#include<algorithm>
using namespace std;
const int o=1010;
int T,n,d[o],p[o],col[o],st[o],tp;
inline bool cmp(int A,int B){return d[A]<d[B];}
int main(){
	for(cin>>T;T--;cout<<endl){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>d[i],p[i]=i,col[i]=0;
		sort(p+1,p+n+1,cmp);
		for(int i=n,asd=0;i;--i) if(!col[p[i]]){
			st[tp=1]=p[i];
			for(int x,D=d[p[i]];D--;){
				cout<<"? "<<p[i]<<endl;cin>>x;
				if(col[x]){for(;tp;col[st[tp--]]=col[x]);break;}
				else st[++tp]=x;
			}
			if(tp) for(++asd;tp;col[st[tp--]]=asd);
		}
		cout<<"!";
		for(int i=1;i<=n;++i) cout<<" "<<col[i];
	}
	return 0;
}