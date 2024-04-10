/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	string a;
	cin>>a;
	int sum=0;
	for(int i=0;i<a.size();i++)sum+=a[i]^48;
	if(sum%3==0)return cout<<a,0;
	if(sum%3==1){
		string ans1,ans2;
		for(int i=a.size()-1;~i;i--)if((a[i]^48)%3==1){
			string b;
			for(int j=0;j<a.size();j++)if(j!=i)b+=a[j];
			if(b.empty())break;
			int now=0;
			while(now+1<b.size()&&b[now]==48)now++;
			ans1=b.substr(now,b.size()-now);
			break;
		}
		vector<int> pos;
		for(int i=a.size()-1;~i;i--)if((a[i]^48)%3==2)pos.pb(i);
		if(pos.size()>=2){
			string b;
			for(int j=0;j<a.size();j++)if(j!=pos[0]&&j!=pos[1])b+=a[j];
			if(b.size()){
				int now=0;
				while(now+1<b.size()&&b[now]==48)now++;
				ans2=b.substr(now,b.size()-now);
			}
		}
		if(ans1.size()<ans2.size())swap(ans1,ans2);
		if(ans1.empty())puts("-1");
		else cout<<ans1;
	}
	else{
		string ans1,ans2;
		for(int i=a.size()-1;~i;i--)if((a[i]^48)%3==2){
			string b;
			for(int j=0;j<a.size();j++)if(j!=i)b+=a[j];
			if(b.empty())break;
			int now=0;
			while(now+1<b.size()&&b[now]==48)now++;
			ans1=b.substr(now,b.size()-now);
			break;
		}
		vector<int> pos;
		for(int i=a.size()-1;~i;i--)if((a[i]^48)%3==1)pos.pb(i);
		if(pos.size()>=2){
			string b;
			for(int j=0;j<a.size();j++)if(j!=pos[0]&&j!=pos[1])b+=a[j];
			if(b.size()){
				int now=0;
				while(now+1<b.size()&&b[now]==48)now++;
				ans2=b.substr(now,b.size()-now);
			}
		}
		if(ans1.size()<ans2.size())swap(ans1,ans2);
		if(ans1.empty())puts("-1");
		else cout<<ans1;
	}
	return 0;
}