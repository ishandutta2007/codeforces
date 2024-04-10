#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define R register int
struct node{
	int l,r;
	string s;
}a[200001];
int main(){
	int t,n,len;
	cin>>t;
	for(R q=0;q<t;q++){
		map<string,int> m;
		cin>>n;
		if(n==1){
			cin>>a[0].s;
			cout<<"0\n\n";
			continue;
		}
		for(R i=1;i<=n;i++){
			cin>>a[i].s;
			m[a[i].s]=1;
			len=a[i].s.length();
			a[i].l=a[i].s[0]-'0';
			a[i].r=a[i].s[len-1]-'0';
		}
		int oo=0,ll=0,ol=0,lo=0;
		for(R i=1;i<=n;i++){
			if(a[i].l+a[i].r==0){
				oo++;
			}else if(a[i].l==0&&a[i].r==1){
				ol++;
			}else if(a[i].l==1&&a[i].r==0){
				lo++;
			}else{
				ll++;
			}
		}
		if(oo&&ll&&ol==0&&lo==0){
			cout<<"-1\n";continue;
		}
		if(ol==lo||ol-lo==1||lo-ol==1){
			cout<<"0\n\n";continue;
		}
		int gb=0;
		if(ol>lo){
			gb=(ol-lo)/2;
			cout<<gb<<endl;
			for(R i=1;i<=n&&gb;i++){
				if(a[i].l==0&&a[i].r==1){
					reverse(a[i].s.begin(),a[i].s.end());
					if(m[a[i].s]==0){
						cout<<i<<" ";
						gb--;
						m[a[i].s]=1;
					}else{
						reverse(a[i].s.begin(),a[i].s.end());
					}
				}
			}
			cout<<endl;
		}else{
			gb=lo-ol>>1;
			cout<<gb<<endl;
			for(R i=1;i<=n&&gb;i++){
				if(a[i].l==1&&a[i].r==0){
					reverse(a[i].s.begin(),a[i].s.end());
					if(m[a[i].s]==0){
						cout<<i<<" ";
						gb--;
						m[a[i].s]=1;
					}else{
						reverse(a[i].s.begin(),a[i].s.end());
					}
				}
			}
			cout<<endl;
		}
	}
    return 0;
}