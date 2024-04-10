#include<iostream>
using namespace std;
#define R register int
#define p 1000000007
inline void Solve(){
	int x,ans;
	scanf("%d",&x);
	string s,t;
	cin>>s;
	int l=s.length();
	ans=l;
	for(R i=0;i<x;i++){
		l=s.length();
		if(l<x&&s[i]>'1'){
			t="";
			for(R j=i+1;j<l;j++){
				t+=s[j];
			}
			for(R j='1';j<s[i];j++){
				s+=t;
				if(s.length()>=x){
					break;
				}
			}
		}
		//cout<<s<<endl;
		ans=(((long long)ans-i-1+p)*(s[i]-'1')%p+ans)%p;
		//cout<<"X"<<ans<<endl;
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}