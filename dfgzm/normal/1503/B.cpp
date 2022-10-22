#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,x1=1,y1=1,x2=1,y2=2;
int main(){
	cin>>n;
	int all=0;
	for(i=1;i<=n*n;i++){
		int c;
		cin>>c;
		if(all){
			int s=6;
			if(c==all)c=all%3+1;
			cout<<s-all-c<<' '<<x1<<' '<<y1<<endl;
			cout.flush();
			y1+=2;if(y1>n)y1=((x1&1^(all-1))?1:2),x1++;
		}else{
			if(c==1){
				cout<<2<<' '<<x2<<' '<<y2<<endl;
				cout.flush();
				y2+=2;if(y2>n)y2=(x2&1?1:2),++x2;
				if(x2>n)all=2;
			}else{
				cout<<1<<' '<<x1<<' '<<y1<<endl;
				cout.flush();
				y1+=2;if(y1>n)y1=(x1&1?2:1),++x1;
				if(x1>n)all=1,x1=x2,y1=y2;
			}
		}
	}
	return 0;
}