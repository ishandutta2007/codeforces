#include<bits/stdc++.h>
using namespace std;
int check1(int a,int b,int c)
{
        if(a+b>c&&a+c>b&&b+c>a)  return 1;
        else return 0;
}
int check2(int a,int b,int c)
{         
         if(a+b==c||a+c==b||b+c==a)  return 1;
         else return 0;
}

int main()
{
	int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	//sort(a,a+4);
	if(check1(a[0],a[1],a[2]) || check1(a[0],a[1],a[3])|| check1(a[0],a[3],a[2])||check1(a[1],a[3],a[2])){
		return 0*printf("TRIANGLE\n");
		
	}
	//10 30 7 20
	else if(check2(a[0],a[1],a[2]) || check2(a[0],a[1],a[3])|| check2(a[0],a[3],a[2])||check2(a[1],a[3],a[2])){
		return 0*printf("SEGMENT\n");
		
	}
	else {
		return 0*printf("IMPOSSIBLE\n");
	}
	return 0;
}