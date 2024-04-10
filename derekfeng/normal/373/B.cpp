#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w,m,k,x,now=1,ans,I;
string s;
int n;
int main(){
	cin>>w>>s>>k;I=x=atoll(s.c_str());n=s.size();
	ans=x-1;
	for(int i=0;i<n;i++)now*=10;
    for(;;){
        ll cost=k*n;
        if((now-x)<=w/cost){
            w-=(now-x)*cost;
            n++;
            ans=now-1;
            x=now;
            now*=10; 
        }else{
            ll ret=w/cost;
            ans+=ret;
            break;
        }
    }
    cout<<ans-I+1;
}