#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
char r,c;
int main()
{
	cin>>r>>c;
	if (r=='a'&&c=='1') {cout<<3;return 0;}
	if (r=='a'&&c=='8') {cout<<3;return 0;}
	if (r=='h'&&c=='1') {cout<<3;return 0;}
	if (r=='h'&&c=='8') {cout<<3;return 0;}
	if (r=='h') {cout<<5;return 0;}
	if (r=='a') {cout<<5;return 0;}
	if (c=='1') {cout<<5;return 0;}
	if (c=='8') {cout<<5;return 0;}
	cout<<8;
	return 0;
}