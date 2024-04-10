#include<bits/stdc++.h>
using namespace std;
int ans=1;
int n;
int a[3][6];
bool ok(int index1,int index2,int x1,int x2){
	bool flag1 = false,flag2 = false;
	for (int i=0;i<6;i++){
		if (a[index1][i]==x1)flag1 = true;
		if (a[index2][i]==x2)flag2 = true;
	}
	if (flag1&&flag2)return true;
	flag1 = false,flag2 = false;
	for (int i=0;i<6;i++){
		if (a[index2][i]==x1)flag1 = true;
		if (a[index1][i]==x2)flag2 = true;
	}
	if (flag1&&flag2)return true;
	return false;
}
bool ok3(int x1,int x2,int x3){
	bool flag1,flag2,flag3;
	flag1 = flag2 = flag3 = false;
	for (int i=0;i<6;i++){
		if (a[0][i]==x1)flag1 = true;
		if (a[1][i]==x2)flag2 = true;
		if (a[2][i]==x3)flag3 = true;
	}
	if (flag1&&flag2&&flag3)return true;
		flag1 = flag2 = flag3 = false;
	for (int i=0;i<6;i++){
		if (a[0][i]==x1)flag1 = true;
		if (a[2][i]==x2)flag2 = true;
		if (a[1][i]==x3)flag3 = true;
	}
	if (flag1&&flag2&&flag3)return true;
		flag1 = flag2 = flag3 = false;
	for (int i=0;i<6;i++){
		if (a[1][i]==x1)flag1 = true;
		if (a[0][i]==x2)flag2 = true;
		if (a[2][i]==x3)flag3 = true;
	}
	if (flag1&&flag2&&flag3)return true;
		flag1 = flag2 = flag3 = false;
	for (int i=0;i<6;i++){
		if (a[1][i]==x1)flag1 = true;
		if (a[2][i]==x2)flag2 = true;
		if (a[0][i]==x3)flag3 = true;
	}
	if (flag1&&flag2&&flag3)return true;
		flag1 = flag2 = flag3 = false;
	for (int i=0;i<6;i++){
		if (a[2][i]==x1)flag1 = true;
		if (a[1][i]==x2)flag2 = true;
		if (a[0][i]==x3)flag3 = true;
	}
	if (flag1&&flag2&&flag3)return true;
		flag1 = flag2 = flag3 = false;
	for (int i=0;i<6;i++){
		if (a[2][i]==x1)flag1 = true;
		if (a[0][i]==x2)flag2 = true;
		if (a[1][i]==x3)flag3 = true;
	}
	if (flag1&&flag2&&flag3)return true;
	return false;
}
bool check(int x){
	if (x<10){
		for (int i=0;i<n;i++){
			for (int j=0;j<6;j++){
				if (a[i][j]==x)return true;
			}
		}
		return false;
	}else if (x<100){
		int x1 = x%10,x2 = x/10;
		if (n==1)return false;
		if (n==2) return ok(0,1,x1,x2);
		return ok(0,1,x1,x2)||ok(0,2,x1,x2)||ok(1,2,x1,x2);
	}else if (x<1000){
		if (n!=3)return false;
		int x1 =x%10;
		int x2 = (x/10)%10;
		int x3 = (x/100); 
		return ok3(x1,x2,x3);
	}else return false;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		for (int j=0;j<6;j++){
			scanf("%d",&a[i][j]);
		}
	}
	while (check(ans)){
		ans++;
	}
	ans--;
	cout<<ans<<endl;
	return 0;
}