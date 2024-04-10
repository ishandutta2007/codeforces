#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,ans[maxn],a[maxn];
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		int sum=0,last=0;
		for(i=1;i<=n;i++)a[i]=s[i-1]-'0',sum+=a[i]==0,last=a[i]?i:last;
		if((sum&1) || (n&1) || a[1]==0 || sum==n || (sum&&last==n-sum))puts("NO");
		else{
			int oth=n-sum;oth/=2;
			for(i=1;i<=n;i++){
				if(!a[i]){
					ans[i]=sum&1;
					sum--;
				}else if(oth)ans[i]=0,oth--;else ans[i]=1;
			}
			int S=0,B=1;
			for(i=1;i<=n;i++){
				S+=ans[i]?-1:1;
				if(S<0)B=0;
			}
			for(i=1;i<=n;i++){
				S+=(ans[i]^a[i]^1)?-1:1;
				if(S<0)B=0;
			}
			if(!B){
				puts("NO");
				continue;
			}
			puts("YES");
			for(i=1;i<=n;i++)printf("%c",ans[i]?')':'(');
			puts("");
			for(i=1;i<=n;i++)printf("%c",(ans[i]^a[i]^1)?')':'(');
			puts("");
		}
	}
	return 0;
}