#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,q,tmp,ans;
int l[5005],r[5005],ch[5005],sum1[5005],sum2[5005];
int l1,r1,l2,r2;
inline void swp(int &x,int &y){
	int t=x;
	x=y;
	y=t;
	return;
}
inline int s1(int l,int r){
	if (l>r)return 0;
	return sum1[r]-sum1[l-1];
}
inline int s2(int l,int r){
	if (l>r)return 0;
	return sum2[r]-sum2[l-1];
}
signed main(){
	cin>>n>>q;
	for (int i=1;i<=q;i++){
		scanf("%d%d",&l[i],&r[i]);
		ch[l[i]]++,ch[r[i]+1]--;
	}
	for (int i=1;i<=n;i++)ch[i]+=ch[i-1];
	for (int i=1;i<=n;i++){
		if (ch[i]>0)tmp++;
		if (ch[i]==1)sum1[i]=sum1[i-1]+1;
		else sum1[i]=sum1[i-1];
		if (ch[i]==2)sum2[i]=sum2[i-1]+1;
		else sum2[i]=sum2[i-1];
	}
	for (int i=1;i<=q;i++)
		for (int j=i+1;j<=q;j++){
			l1=l[i],l2=l[j],r1=r[i],r2=r[j];
			if (l1>l2)swp(l1,l2),swp(r1,r2);
			if (r1>=l2){
				if (r1>=r2)ans=max(ans,tmp-s1(l1,l2-1)-s2(l2,r2)-s1(r2+1,r1));
				else ans=max(ans,tmp-s1(l1,l2-1)-s2(l2,r1)-s1(r1+1,r2));
			}
			else ans=max(ans,tmp-s1(l1,r1)-s1(l2,r2));
		}
	cout<<ans<<endl;
	return 0;
}