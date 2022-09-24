#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int a[100005];
int b[100005];

int main()
 {
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	int f=0;
	for(int i=1;!f&&i<=n/3;i++)
		if(n%i==0) {
			for(int j=0;j<n;j++)
				if(j<i) b[j]=a[j];
				else b[j] = b[j-i]+a[j];
			for(int j=n-i;j<n;j++)
				if(b[j]==n/i)
					f=1;
		}
        if(f)	cout << "YES";
        else cout <<"NO";
	return 0;
}