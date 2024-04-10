#include <iostream>

using namespace std;

int main()
{
	int n, k, ct[105][105] = {0};
	char brd[105][105];
	cin >> n >> k;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> brd[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			if(brd[i][j] != '.') continue;
			bool vir = true, hor = true;
			for(int l=0;l<k;l++) {
				if(brd[i+l][j] != '.') hor = false;
				if(brd[i][j+l] != '.') vir = false;
			}
			if(hor) 
				for(int l=0;l<k;l++) 
					ct[i+l][j]++;
			if(vir) 
				for(int l=0;l<k;l++) 
					ct[i][j+l]++;
		}
	int x = 0, y = 0, z = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			if(ct[i][j] > z) {
				x = i;
				y = j;
				z = ct[i][j];
			}
		}
	cout << x+1 << " " << y+1 << endl;
}