#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int module = 1e9+7;

int binPow(int base, int power)
{
	if (power==0)
		return 1;
	if (power%2==1)
		return (1LL*binPow(base,power-1)*base)%module;
	int x=binPow(base,power/2);
	return (1LL*x*x)%module;
}

int C(int n, int k)
{
	if (n<k)
		return 0;
	if (n==k)
		return 1;
	int num=1;
	for (int i=n; i>n-k; i--)
		num = (1LL*num*i)%module;
	int den=1;
	for (int i=2; i<=k; i++)
		den = (1LL*den*i)%module;
	den = binPow(den, module-2);
	num = (1LL*num*den)%module;
	return num;
}

string m;
int a[10];

void calc(int cnt, int happy)
{
	for (int i=0; i<=cnt; i++)
	{
		int mn=(1LL*binPow(2,i)*binPow(8,cnt-i))%module;
		a[happy+i] = (a[happy+i] + 
			(1LL*mn*C(cnt,i))%module)%module;
	}
}

void calc2(int length)
{
	for (int i=1; i<10; i++)
		calc(length-1, i==4 || i==7);
}

void go(int pos, int happy)
{
	if (pos >= m.length())
		a[happy] = (a[happy]+1)%module;
	else
	{
		int cur = m[pos]-'0';
		for (int i=1; i<cur; i++)
			calc(m.length()-pos-1, happy+(i==4 || i==7));
		if (pos!=0 && cur!=0)
			calc(m.length()-pos-1, happy);
		go(pos+1, happy+(cur==4 || cur==7));
	}
}

int b[10];

int P(int n,int k)
{
	int r=1;
	for (int i=n; i>n-k; i--)
		r = (1LL*r*i)%module;
	return r;
}

int main()
{
	cin >> m;
	go(0,0);
	for (int i=m.length()-1; i>0; i--)
		calc2(i);
	int ans=0;
	for (int i0=1; i0<10; i0++)
		for (int i1=0; i1<i0; i1++)
			for (int i2=0; i2<i0; i2++)
				for (int i3=0; i3<i0; i3++)
					for (int i4=0; i4<i0; i4++)
						for (int i5=0; i5<i0; i5++)
							for (int i6=0; i6<i0; i6++)
								if (i1+i2+i3+i4+i5+i6<i0)
								{
									for (int i=0; i<10; i++)
										b[i]=0;
									b[i1]++;b[i2]++;
									b[i3]++;b[i4]++;
									b[i5]++;b[i6]++;

									int mn = 1;
									for (int i=0; i<10; i++)
										mn = (1LL*mn*P(a[i],b[i]))%module;
									mn = (1LL*mn*a[i0])%module;
									ans = (ans + mn)%module;
								}
	cout << ans << endl;
	//system("pause");
	return 0;
}