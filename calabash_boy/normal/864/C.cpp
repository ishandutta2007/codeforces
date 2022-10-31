#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,bb,b,f,k,c1,c2,rest,cc;
int main(){
	cin>>a>>b>>f>>k;
	LL c1 = f;
	LL c2 = a-f;
	LL ans =0;
	LL tot =0;
	LL rest = b;
	if (c1>b||c2>b){
		cout<<-1<<endl;
		return 0;
	}
	bool atleft =true;
	while (tot<k){
//		cout<<tot<<" "<<atleft<<" "<<rest<<" "<<ans<<endl;
		LL round = rest/a;
		if (tot+round>=k){
			break;
		}
		if (round*a==rest){
			round--;
		}
		LL temp = rest-round*a;
		if (round<0){
			cout<<-1<<endl;
			return 0;
		}
		if (atleft){
			if (round&1){
				if (c2>temp){
					temp+=a;
					round--;
				}
			}else{
				if (c1>temp){
					temp+=a;
					round--;
				}
			}
		}else{
			if (round&1){
				if (c1>temp){
					temp+=a;
					round--;
				}
			}else{
				if (c2>temp){
					temp+=a;
					round--;
				}
			}
		}
		
		if (round<0){
			cout<<-1<<endl;
			return 0;
		}
		tot+=round;
		if (tot>=k){
			break;
		}
		if (atleft){
			if (round&1){
				rest = b-c1;
				tot++;
				ans++;
			}else{
				rest = b-c2;
				tot++;
				ans++;
				atleft = false;
			}
		}else{
			if (round&1){
				rest = b-c2;
				tot++;
				ans++;
			}else{
				rest = b-c1;
				tot++;
				ans++;
				atleft = true;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}