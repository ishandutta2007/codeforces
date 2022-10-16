#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b,c,ans=0,res=0;
		cin>>a>>b>>c;
		if(a>3&&b>3&&c>3){cout<<7<<endl;continue;}
		if(a)a--,ans++;
		if(b)b--,ans++;
		if(c)c--,ans++;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++){
					a-=(i+j);
					b-=(i+k);
					c-=(j+k);
					if(a>=0&&b>=0&&c>=0)res=max(res,i+j+k);
					a+=(i+j);
					b+=(i+k);
					c+=(j+k);
				}
		cout<<ans+res<<endl;
	}
}