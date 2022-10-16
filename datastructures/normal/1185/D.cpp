#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#define int long long
using namespace std;
int n,ch[200005];
map <int,int>mp;
struct node{
	int num,id;
}a[200005];
bool cmp(node a,node b){
	return a.num<b.num;
}
inline bool check(int del){
	int delta;
	if (del==1)delta=a[3].num-a[2].num;
	else if (del==2)delta=a[3].num-a[1].num;
	else delta=a[2].num-a[1].num;
	for (int i=((del==1||del==2)?3:2);i<=n;i++){
		if (i==del)continue;
		if (i==del+1){
			if (a[i].num-a[i-2].num!=delta)return 0;
		}
		else{
			if (a[i].num-a[i-1].num!=delta)return 0;
		}
	}
	return 1;
}
signed main(){
//	freopen("1185D.in","r",stdin);
//	freopen("1185D.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i].num),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	a[0].num=a[0].id=0;
	if (n==2||n==3){
		cout<<1<<endl;
		return 0;
	}
	if (n<=1000){
		for (int i=1;i<=n;i++)
			if (check(i)){
				cout<<a[i].id<<endl;
				return 0;
			}
		cout<<-1<<endl;
		return 0;
	}
	for (int i=2;i<=n;i++)ch[i]=a[i].num-a[i-1].num;
	int cnt=0;
	for (int i=2;i<=n;i++){
		mp[ch[i]]++;
		if (mp[ch[i]]>cnt)cnt=mp[ch[i]];
	}
	if (check(1)){
		cout<<a[1].id<<endl;
		return 0;
	}
	if (check(n)){
		cout<<a[n].id<<endl;
		return 0;
	}
	if (mp[0]==cnt){
		for (int i=2;i<n;i++){
			if (a[i].num!=a[i+1].num||a[i].num!=a[i-1].num){
				if (check(i)){
					cout<<a[i].id<<endl;
					return 0;
				}
			}
		}
		cout<<-1<<endl;
		return 0;
	}
	for (int i=2;i<n;i++){
		if (mp[a[i+1].num-a[i-1].num]==cnt){
			if (check(i)){
				cout<<a[i].id<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
}